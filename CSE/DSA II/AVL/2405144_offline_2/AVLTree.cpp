#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define sajai(x) sort(x.begin(), x.end())
#define rsort(a) sort(a.begin(), a.end(), greater<>())
#define ulta(a) reverse(a.begin(), a.end())
#define mucho(a, j) a.erase(a.begin() + j)
#define choto(a) *min_element(a.begin(), a.end())
#define boro(a) *max_element(a.begin(), a.end())
#define jog(a) accumulate(a.begin(), a.end(), 0LL)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

struct Node
{
    ll key, height;
    Node *left, *right;

    Node(ll x)
    {
        key = x;
        height = 1;
        left = right = nullptr;
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

ll getBalance(Node *node)
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

Node *insertNode(Node *node, ll key, bool &inserted)
{
    // TODO:
    // ordinary BST insertion
    // duplicate => inserted = false and return unchanged node
    // otherwise rebalance on return path
    return node;
}

Node *minimumNode(Node *node)
{
    // TODO: return leftmost node
    return node;
}

Node *eraseNode(Node *node, ll key, bool &erased)
{
    // TODO:
    // ordinary BST deletion
    // 0 child / 1 child / 2 children
    // for 2 children use inorder successor
    // then rebalance while returning toward root
    return node;
}

bool findKey(ll key)
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

void clearTree(Node *node)
{
    // TODO: postorder delete
}

struct TimingData
{
    ll count = 0;
    ll total_ns = 0;
};

void addTiming(TimingData &x, ll ns)
{
    x.count++;
    x.total_ns += ns;
}

void printTiming(string operation, TimingData x)
{
    cout << operation << "," << x.count << "," << x.total_ns << ",";
    if (x.count == 0)
        cout << "N/A";
    else
        cout << x.total_ns / x.count;
    cout << tata;
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc != 3)
    {
        cerr << "Usage: ./avl_tree <input-file> <output-file>" << tata;
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
    char cmd;

    while (fin >> cmd)
    {
        if (cmd == 'I')
        {
            ll x;
            fin >> x;

            bool inserted = false;

            auto st = chrono::steady_clock::now();
            root = insertNode(root, x, inserted);
            auto en = chrono::steady_clock::now();

            addTiming(insertTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            if (!inserted)
                fout << "duplicate" << tata;
            else
                fout << serialize(root) << tata;
        }
        else if (cmd == 'D')
        {
            ll x;
            fin >> x;

            bool erased = false;

            auto st = chrono::steady_clock::now();
            root = eraseNode(root, x, erased);
            auto en = chrono::steady_clock::now();

            addTiming(deleteTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            if (!erased)
                fout << "not found" << tata;
            else
                fout << serialize(root) << tata;
        }
        else if (cmd == 'F')
        {
            ll x;
            fin >> x;

            auto st = chrono::steady_clock::now();
            bool found = findKey(x);
            auto en = chrono::steady_clock::now();

            addTiming(findTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            fout << (found ? "found" : "not found") << tata;
        }
        else if (cmd == 'T')
        {
            vector<ll> ans;

            auto st = chrono::steady_clock::now();
            inorder(root, ans);
            auto en = chrono::steady_clock::now();

            addTiming(traverseTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            loop(i, 0, ans.size())
            {
                if (i)
                    fout << " ";
                fout << ans[i];
            }
            fout << tata;
        }
    }

    cout << "operation,count,total_ns,average_ns" << tata;
    printTiming("insert", insertTime);
    printTiming("delete", deleteTime);
    printTiming("find", findTime);
    printTiming("traverse", traverseTime);

    clearTree(root);
    return 0;
}
