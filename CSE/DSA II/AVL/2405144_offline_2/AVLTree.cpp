#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define sajai(x) sort(x.begin(), x.end())
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

struct Node
{
    ll key, h;
    Node *l, *r;
    Node(ll x)
    {
        key = x;
        h = 1;
        l = r = nullptr;
    }
};

Node *root = nullptr;

ll getHeight(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->h;
}

void updateHeight(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    node->h = 1 + max(getHeight(node->l), getHeight(node->r));
}

ll Balance_dekhao(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return getHeight(node->l) - getHeight(node->r);
}

Node *rotateLeft(Node *node)
{
    Node *rightChild = node->r;
    Node *majherSubtree = rightChild->l;

    rightChild->l = node;
    node->r = majherSubtree;

    // First update the lower node, then the new root.
    updateHeight(node);
    updateHeight(rightChild);

    return rightChild;
}

Node *rotateRight(Node *node)
{
    Node *leftChild = node->l;
    Node *majherSubtree = leftChild->r;

    leftChild->r = node;
    node->l = majherSubtree;

    // First update the lower node, then the new root.
    updateHeight(node);
    updateHeight(leftChild);

    return leftChild;
}

Node *rebalance(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    updateHeight(node);
    ll balance = Balance_dekhao(node);

    // Left-heavy subtree: LL or LR case.
    if (balance > 1)
    {
        if (Balance_dekhao(node->l) < 0)
        {
            node->l = rotateLeft(node->l); // LR: first left rotation
        }
        return rotateRight(node); // LL: right rotation
    }

    // Right-heavy subtree: RR or RL case.
    if (balance < -1)
    {
        if (Balance_dekhao(node->r) > 0)
        {
            node->r = rotateRight(node->r); // RL: first right rotation
        }
        return rotateLeft(node); // RR: left rotation
    }

    return node;
}

Node *insert_Node(Node *node, ll key, bool &inserted)
{
    if (node == nullptr)
    {
        inserted = true;
        return new Node(key);
    }

    if (key < node->key)
    {
        node->l = insert_Node(node->l, key, inserted);
    }
    else if (key > node->key)
    {
        node->r = insert_Node(node->r, key, inserted);
    }
    else
    {
        inserted = false;
        return node;
    }

    return rebalance(node);
}

Node *min_Node(Node *node)
{
    Node *current = node;
    while (current->l != nullptr)
    {
        current = current->l;
    }
    return current;
}

Node *Node_sorao(Node *node, ll key, bool &erased)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (key < node->key)
    {
        node->l = Node_sorao(node->l, key, erased);
    }
    else if (key > node->key)
    {
        node->r = Node_sorao(node->r, key, erased);
    }
    else
    {
        erased = true;

        // No left child: the right child takes this node's place.
        if (node->l == nullptr)
        {
            Node *temp = node->r;
            delete node;
            return temp;
        }

        // No right child: the left child takes this node's place.
        if (node->r == nullptr)
        {
            Node *temp = node->l;
            delete node;
            return temp;
        }

        // Two children: copy the inorder successor, then remove it.
        Node *successor = min_Node(node->r);
        node->key = successor->key;
        bool dummy = false;
        node->r = Node_sorao(node->r, successor->key, dummy);
    }

    // Deletion can unbalance several ancestors, so rebalance every
    // node while recursion returns toward the root.
    return rebalance(node);
}

bool key_khujo(ll key)
{
    Node *current = root;
    while (current != nullptr)
    {
        if (key == current->key)
        {
            return true;
        }
        if (key < current->key)
        {
            current = current->l;
        }
        else
        {
            current = current->r;
        }
    }
    return false;
}

void inorder(Node *node, vector<ll> &ans)
{
    if (node == nullptr)
    {
        return;
    }
    inorder(node->l, ans);
    ans.pb(node->key);
    inorder(node->r, ans);
}

string serialize(Node *node)
{
    if (node == nullptr)
    {
        return "";
    }

    string ans = to_string(node->key);

    // Parentheses are printed only for a non-leaf node. Both child
    // positions are kept, even if one of them is empty.
    if (node->l != nullptr || node->r != nullptr)
    {
        ans += "(";
        ans += serialize(node->l);
        ans += ",";
        ans += serialize(node->r);
        ans += ")";
    }
    return ans;
}

void Tree_mucho(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    Tree_mucho(node->l);
    Tree_mucho(node->r);
    delete node;
}

struct TimingData
{
    ll count = 0, total_ns = 0;
};

void time_jog(TimingData &x, ll ns)
{
    x.count++;
    x.total_ns += ns;
}

void time_print(string operation, TimingData x)
{
    cout << operation << "," << x.count << "," << x.total_ns << ",";
    if (x.count == 0)
    {
        cout << "N/A";
    }
    else
    {
        cout << x.total_ns / x.count;
    }
    cout << tata;
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (argc != 3)
    {
        return 1;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    if (!fin || !fout)
    {
        cerr << "File open error" << tata;
        return 1;
    }
    TimingData insertTime, deleteTime, findTime, traverseTime;
    char c;
    while (fin >> c)
    {
        if (c == 'I')
        {
            ll x;
            fin >> x;
            bool x1 = false;
            auto a = chrono::steady_clock::now();
            root = insert_Node(root, x, x1);
            auto b = chrono::steady_clock::now();
            time_jog(insertTime, chrono::duration_cast<chrono::nanoseconds>(b - a).count());
            if (!x1)
            {
                fout << "duplicate" << tata;
            }
            else
            {
                fout << serialize(root) << tata;
            }
        }
        else if (c == 'D')
        {
            ll x;
            fin >> x;
            bool e = false;
            auto a = chrono::steady_clock::now();
            root = Node_sorao(root, x, e);
            auto b = chrono::steady_clock::now();
            time_jog(deleteTime, chrono::duration_cast<chrono::nanoseconds>(b - a).count());
            if (!e)
            {
                fout << "not found" << tata;
            }
            else
            {
                fout << serialize(root) << tata;
            }
        }
        else if (c == 'F')
        {
            ll x;
            fin >> x;
            auto a = chrono::steady_clock::now();
            bool x1 = key_khujo(x);
            auto b = chrono::steady_clock::now();
            time_jog(findTime, chrono::duration_cast<chrono::nanoseconds>(b - a).count());
            if (x1)
            {
                fout << "found" << tata;
            }
            else
            {
                fout << "not found" << tata;
            }
        }
        else if (c == 'T')
        {
            vector<ll> v;
            auto a = chrono::steady_clock::now();
            inorder(root, v);
            auto b = chrono::steady_clock::now();
            time_jog(traverseTime, chrono::duration_cast<chrono::nanoseconds>(b - a).count());
            loop(i, 0, v.size())
            {
                if (i)
                {
                    fout << " ";
                }
                fout << v[i];
            }
            fout << tata;
        }
    }
    cout << "operation,count,total_ns,average_ns" << tata;
    time_print("insert", insertTime);
    time_print("delete", deleteTime);
    time_print("find", findTime);
    time_print("traverse", traverseTime);
    Tree_mucho(root);
    return 0;
}