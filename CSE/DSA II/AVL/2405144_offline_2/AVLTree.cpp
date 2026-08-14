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
    // TODO: return 0 for nullptr, otherwise node->height
    return 0;
}

void updateHeight(Node *node)
{
    // TODO: height = 1 + max(left height, right height)
}

ll Balance_dekhao(Node *node)
{
    // TODO: height(left) - height(right)
    return 0;
}

Node *rotateLeft(Node *node)
{
    // TODO: AVL left rotation
    return node;
}

Node *rotateRight(Node *node)
{
    // TODO: AVL right rotation
    return node;
}

Node *rebalance(Node *node)
{
    // TODO:
    // 1) update height
    // 2) calculate balance
    // 3) handle LL, LR, RR, RL
    return node;
}

Node *insert_Node(Node *node, ll key, bool &inserted)
{
    // TODO:
    // ordinary BST insertion
    // duplicate => inserted = false and return unchanged node
    // otherwise rebalance on return path
    return node;
}

Node *min_Node(Node *node)
{
    // TODO: return leftmost node
    return node;
}

Node *Node_sorao(Node *node, ll key, bool &erased)
{
    // TODO:
    // ordinary BST deletion
    // 0 child / 1 child / 2 children
    // for 2 children use inorder successor
    // then rebalance while returning toward root
    return node;
}

bool key_khujo(ll key)
{
    // TODO: ordinary BST search from root
    return false;
}

void inorder(Node *node, vector<ll> &ans)
{
    // TODO: left, root, right
}

string serialize(Node *node)
{
    // Required:
    // empty -> ""
    // leaf -> "5"
    // one/two children -> "5(1,9)", "5(,9)", "5(1,)"
    return "";
}

void Tree_mucho(Node *node)
{
    // TODO: postorder delete
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