#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename Key, typename Value>
class ListBST : public BST<Key, Value>
{
private:
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node *root;
    size_t node_count;

    void clean(Node *node)
    {
        if (!node)
            return;
        clean(node->left);
        clean(node->right);
        delete node;
    }

    Node *insrt(Node *node, Key key, Value value, bool &success)
    {
        if (!node)
        {
            success = true;
            node_count++;
            return new Node(key, value);
        }
        if (key < node->key)
            node->left = insrt(node->left, key, value, success);
        else if (key > node->key)
            node->right = insrt(node->right, key, value, success);
        else
        {
            success = false;
        }
        return node;
    }

    Node *Find(Node *node, Key key) const
    {
        if (!node)
            return nullptr;
        if (key < node->key)
            return Find(node->left, key);
        if (key > node->key)
            return Find(node->right, key);
        return node;
    }

    Node *min_node(Node *node) const
    {
        if (!node)
            return nullptr;
        while (node->left)
            node = node->left;
        return node;
    }

    Node *max_node(Node *node) const
    {
        if (!node)
            return nullptr;
        while (node->right)
            node = node->right;
        return node;
    }

    Node *rmv(Node *node, Key key, bool &yo)
    {
        if (!node)
            return nullptr;
        if (key < node->key)
            node->left = rmv(node->left, key, yo);
        else if (key > node->key)
            node->right = rmv(node->right, key, yo);
        else
        {
            yo = true;
            node_count--;
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = min_node(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = rmv(node->right, temp->key, yo);
            node_count++;
        }
        return node;
    }

    void inorder(Node *n) const
    {
        if (!n)
            return;
        inorder(n->left);
        cout << "(" << n->key << ":" << n->value << ") ";
        inorder(n->right);
    }

    void preorder(Node *n) const
    {
        if (!n)
            return;
        cout << "(" << n->key << ":" << n->value << ") ";
        preorder(n->left);
        preorder(n->right);
    }

    void postorder(Node *n) const
    {
        if (!n)
            return;
        postorder(n->left);
        postorder(n->right);
        cout << "(" << n->key << ":" << n->value << ") ";
    }

    void Print(Node *n) const
    {
        if (!n)
            return;
        cout << "(" << n->key << ":" << n->value;
        if (n->left || n->right)
        {
            cout << " ";
            if (n->left)
                Print(n->left);
            else
                cout << "()";

            if (n->right)
            {
                cout << " ";
                Print(n->right);
            }
        }
        cout << ")";
    }

    void printR(Node *n) const
    {
        if (!n)
            return;
        printR(n->left);
        cout << "  " << n->key << ": " << n->value << endl;
        printR(n->right);
    }

public:
    ListBST() : root(nullptr), node_count(0) {}
    ~ListBST() { clear(); }

    bool insert(Key key, Value value) override
    {
        bool ok = false;
        root = insrt(root, key, value, ok);
        return ok;
    }

    bool remove(Key key) override
    {
        bool ok = false;
        root = rmv(root, key, ok);
        return ok;
    }

    bool find(Key key) const override
    {
        return Find(root, key) != nullptr;
    }

    Value get(Key key) const override
    {
        Node *n = Find(root, key);
        if (!n)
            return Value();
        return n->value;
    }

    void update(Key key, Value value) override
    {
        Node *n = Find(root, key);
        if (n)
            n->value = value;
    }

    void clear() override
    {
        clean(root);
        root = nullptr;
        node_count = 0;
    }

    size_t size() const override
    {
        return node_count;
    }

    bool empty() const override
    {
        return node_count == 0;
    }

    Key find_min() const override
    {
        Node *n = min_node(root);
        if (!n)
            return Key();
        return n->key;
    }

    Key find_max() const override
    {
        Node *n = max_node(root);
        if (!n)
            return Key();
        return n->key;
    }

    void print(char traversal_type = 'D') const override
    {
        if (traversal_type == 'I')
        {
            cout << "BST (In-order): ";
            inorder(root);
            cout << endl;
        }
        else if (traversal_type == 'P')
        {
            cout << "BST (Pre-order): ";
            preorder(root);
            cout << endl;
        }
        else if (traversal_type == 'O')
        {
            cout << "BST (Post-order): ";
            postorder(root);
            cout << endl;
        }
        else if (traversal_type == 'R')
        {
            printR(root);
        }
        else
        {
            cout << "BST (Default): ";
            Print(root);
            cout << endl;
        }
    }
};

#endif // LISTBST_H