#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * Binary Search Tree implementation using linked list structure
 *
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value>
{
private:
    /**
     * Node class for the binary search tree
     */
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr)
        {
        }
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

    // Helper to insert node recursively
    Node *insrt(Node *node, Key key, Value value, int flag)
    {
        if (!node)
        {
            flag = 1;
            node_count++;
            return new Node(key, value);
        }
        if (key < node->key)
        {
            node->left = insrt(node->left, key, value, flag);
        }
        else if (key > node->key)
        {
            node->right = insrt(node->right, key, value, flag);
        }
        else
        {
            flag = 0;
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

    Node *rmv(Node *node, Key key, int flag)
    {
        if (!node)
            return nullptr;
        if (key < node->key)
        {
            node->left = rmv(node->left, key, flag);
        }
        else if (key > node->key)
        {
            node->right = rmv(node->right, key, flag);
        }
        else
        {
            flag = 1;
            node_count--;
            if (!node->left)
            {
                Node *r = node->right;
                delete node;
                return r;
            }
            else if (!node->right)
            {
                Node *l = node->left;
                delete node;
                return l;
            }
            else
            {
                Node *MinR = min_node(node->right);
                node->key = MinR->key;
                node->value = MinR->value;
                node->right = rmv(node->right, MinR->key, flag);
            }
        }
        return node;
    }

    void inorder(Node *n) const
    {
        if (!n)
            return;
        cout << "(";
        inorder(n->left);
        if (n->left)
            cout << " ";
        cout << n->key << ":" << n->value;
        if (n->right)
            cout << " ";
        inorder(n->right);
        cout << ")";
    }
    void preorder(Node *n) const
    {
        if (!n)
            return;
        cout << "(" << n->key << ":" << n->value << " ";
        preorder(n->left);
        preorder(n->right);
        cout << ")";
    }
    void postorder(Node *n) const
    {
        if (!n)
            return;
        cout << "(";
        postorder(n->left);
        postorder(n->right);
        cout << n->key << ":" << n->value << ")";
    }

public:
    ListBST() : root(nullptr), node_count(0)
    {
    }
    ~ListBST()
    {
        clear();
    }

    // Insert a key-value pair into the BST
    bool insert(Key key, Value value) override
    {
        bool f = false;
        root = insrt(root, key, value, f);
        return f;
    }

    // Remove a key-value pair from the BST
    bool remove(Key key) override
    {
        bool rmvd = false;
        root = rmv(root, key, rmvd);
        return rmvd;
    }

    // Find if a key exists in the BST
    bool find(Key key) const override
    {
        return Find(root, key) != nullptr;
    }

    // Find a value associated with a given key
    Value get(Key key) const override
    {
        Node *n = Find(root, key);
        if (!n)
        {
            cout << "Key not found" << endl;
            return Value();
        }
        return n->value;
    }

    // Update the value associated with a given key
    void update(Key key, Value value) override
    {
        Node *n = Find(root, key);
        if (!n)
        {
            cout << "Key not found" << endl;
            return;
        }
        n->value = value;
    }

    // Clear all elements from the BST
    void clear() override
    {
        clean(root);
        root = nullptr;
        node_count = 0;
    }

    // Get the number of keys in the BST
    size_t size() const override
    {
        return node_count;
    }

    // Check if the BST is empty
    bool empty() const override
    {
        return node_count == 0;
    }

    // Find the minimum key in the BST
    Key find_min() const override
    {
        Node *n = min_node(root);
        if (!n)
            throw std::runtime_error("BST is empty");
        return n->key;
    }

    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override
    {
        Node *n = max_node(root);
        if (!n)
            throw std::runtime_error("BST is empty");
        return n->key;
    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override
    {
        if (traversal_type == 'I')
        {
            cout << "BST (In-order): ";
            inorder(root);
        }
        else if (traversal_type == 'P')
        {
            cout << "BST (Pre-order): ";
            preorder(root);
        }
        else if (traversal_type == 'O')
        {
            cout << "BST (Post-order): ";
            postorder(root);
        }
        else
        {
            cout << "BST (Default): ";
            inorder(root);
        }
        cout << endl;
    }
};

#endif // LISTBST_H