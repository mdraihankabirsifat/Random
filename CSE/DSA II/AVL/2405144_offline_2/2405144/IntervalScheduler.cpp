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
#define yes fout << "yes" << tata
#define no fout << "no" << tata

struct Node
{
    ll id, start, end;
    ll h, maxEnd;
    Node *l, *r;
    Node(ll _id, ll _start, ll _end)
    {
        id = _id;
        start = _start;
        end = _end;
        h = 1;
        maxEnd = _end;
        l = r = nullptr;
    }
};

struct Event
{
    ll start, end;
};

Node *root = nullptr;
ll nextId = 1;
unordered_map<ll, Event> events;

ll getHeight(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->h;
}

ll getMaxEnd(Node *node)
{
    if (node == nullptr)
    {
        return LLONG_MIN;
    }
    return node->maxEnd;
}

void updateNode(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    node->h = 1 + max(getHeight(node->l), getHeight(node->r));
    node->maxEnd = max(node->end, max(getMaxEnd(node->l), getMaxEnd(node->r)));
}

ll Balance_dekhao(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return getHeight(node->l) - getHeight(node->r);
}

bool smaller(ll s1, ll id1, ll s2, ll id2)
{
    if (s1 != s2)
    {
        return s1 < s2;
    }
    return id1 < id2;
}

Node *rotateLeft(Node *node)
{
    Node *rightChild = node->r;
    Node *majherSubtree = rightChild->l;

    rightChild->l = node;
    node->r = majherSubtree;

    // updateNode fixes both height and maxEnd.
    updateNode(node);
    updateNode(rightChild);

    return rightChild;
}

Node *rotateRight(Node *node)
{
    Node *leftChild = node->l;
    Node *majherSubtree = leftChild->r;

    leftChild->r = node;
    node->l = majherSubtree;

    // updateNode fixes both height and maxEnd.
    updateNode(node);
    updateNode(leftChild);

    return leftChild;
}

Node *rebalance(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    updateNode(node);
    ll balance = Balance_dekhao(node);

    // Left-heavy subtree: LL or LR case.
    if (balance > 1)
    {
        if (Balance_dekhao(node->l) < 0)
        {
            node->l = rotateLeft(node->l);
        }
        return rotateRight(node);
    }

    // Right-heavy subtree: RR or RL case.
    if (balance < -1)
    {
        if (Balance_dekhao(node->r) > 0)
        {
            node->r = rotateRight(node->r);
        }
        return rotateLeft(node);
    }

    return node;
}

Node *insertNode(Node *node, ll id, ll start, ll end)
{
    if (node == nullptr)
    {
        return new Node(id, start, end);
    }

    if (smaller(start, id, node->start, node->id))
    {
        node->l = insertNode(node->l, id, start, end);
    }
    else
    {
        node->r = insertNode(node->r, id, start, end);
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

Node *eraseNode(Node *node, ll start, ll id)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (smaller(start, id, node->start, node->id))
    {
        node->l = eraseNode(node->l, start, id);
    }
    else if (smaller(node->start, node->id, start, id))
    {
        node->r = eraseNode(node->r, start, id);
    }
    else
    {
        // Node with zero or one child.
        if (node->l == nullptr)
        {
            Node *temp = node->r;
            delete node;
            return temp;
        }
        if (node->r == nullptr)
        {
            Node *temp = node->l;
            delete node;
            return temp;
        }

        // Node with two children: copy the inorder successor's full event.
        Node *successor = min_Node(node->r);
        node->id = successor->id;
        node->start = successor->start;
        node->end = successor->end;
        node->r = eraseNode(node->r, successor->start, successor->id);
    }

    return rebalance(node);
}

bool overlap(ll s1, ll e1, ll s2, ll e2)
{
    return s1 < e2 && s2 < e1;
}

bool conflictNode(Node *node, ll qs, ll qe)
{
    Node *current = node;

    // Only one promising root-to-leaf path is followed.
    while (current != nullptr)
    {
        if (overlap(current->start, current->end, qs, qe))
        {
            return true;
        }

        // The left subtree can contain an overlap only if some interval
        // in it ends after the query starts.
        if (current->l != nullptr && current->l->maxEnd > qs)
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

void overlapsNode(Node *node, ll qs, ll qe, vector<ll> &ans)
{
    if (node == nullptr || node->maxEnd <= qs)
    {
        return;
    }

    overlapsNode(node->l, qs, qe, ans);

    if (overlap(node->start, node->end, qs, qe))
    {
        ans.pb(node->id);
    }

    // All nodes in the right subtree start no earlier than this node.
    // So start >= qe means that entire right subtree is unnecessary.
    if (node->start < qe)
    {
        overlapsNode(node->r, qs, qe, ans);
    }
}

void atNode(Node *node, ll t, vector<ll> &ans)
{
    if (node == nullptr || node->maxEnd <= t)
    {
        return;
    }

    atNode(node->l, t, ans);

    if (node->start <= t && t < node->end)
    {
        ans.pb(node->id);
    }

    // Right-subtree starts are >= this node's start.
    if (node->start <= t)
    {
        atNode(node->r, t, ans);
    }
}

Node *nextNode(ll t)
{
    Node *current = root;
    Node *answer = nullptr;

    while (current != nullptr)
    {
        if (current->start >= t)
        {
            answer = current;
            current = current->l;
        }
        else
        {
            current = current->r;
        }
    }
    return answer;
}

string serialize(Node *node)
{
    if (node == nullptr)
    {
        return "";
    }

    string ans = to_string(node->id);
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
    TimingData addTime, removeTime, updateTime;
    TimingData conflictTime, overlapsTime, atTime, nextTime;
    string c;
    while (fin >> c)
    {
        if (c == "ADD")
        {
            ll s, e;
            fin >> s >> e;
            auto a = chrono::steady_clock::now();
            ll id = nextId++;
            root = insertNode(root, id, s, e);
            events[id] = {s, e};
            auto b = chrono::steady_clock::now();
            time_jog(addTime, chrono::duration_cast<chrono::nanoseconds>(b - a).count());
            fout << serialize(root) << tata;
        }
        else if (c == "REMOVE")
        {
            ll x;
            fin >> x;
            auto a = chrono::steady_clock::now();
            bool y = false;
            auto it = events.find(x);
            if (it != events.end())
            {
                root = eraseNode(root, it->second.start, x);
                events.erase(it);
                y = true;
            }
            auto b = chrono::steady_clock::now();
            time_jog(removeTime, chrono::duration_cast<chrono::nanoseconds>(b - a).count());
            if (!y)
            {
                fout << "not found" << tata;
            }
            else
            {
                fout << serialize(root) << tata;
            }
        }
        else if (c == "UPDATE")
        {
            ll x, s, e;
            fin >> x >> s >> e;
            auto a = chrono::steady_clock::now();
            bool y = false;
            auto it = events.find(x);
            if (it != events.end())
            {
                root = eraseNode(root, it->second.start, x);
                root = insertNode(root, x, s, e);
                it->second = {s, e};
                y = true;
            }
            auto b = chrono::steady_clock::now();
            time_jog(updateTime, chrono::duration_cast<chrono::nanoseconds>(b - a).count());
            if (!y)
            {
                fout << "not found" << tata;
            }
            else
            {
                fout << serialize(root) << tata;
            }
        }
        else if (c == "CONFLICT")
        {
            ll s, e;
            fin >> s >> e;
            auto a = chrono::steady_clock::now();
            bool x = conflictNode(root, s, e);
            auto b = chrono::steady_clock::now();
            time_jog(conflictTime, chrono::duration_cast<chrono::nanoseconds>(b - a).count());
            if (x)
            {
                yes;
            }
            else
            {
                no;
            }
        }
        else if (c == "OVERLAPS")
        {
            ll s, e;
            fin >> s >> e;
            vector<ll> v;
            auto a = chrono::steady_clock::now();
            overlapsNode(root, s, e, v);
            auto b = chrono::steady_clock::now();
            time_jog(overlapsTime, chrono::duration_cast<chrono::nanoseconds>(b - a).count());
            if (v.empty())
            {
                fout << "none" << tata;
            }
            else
            {
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
        else if (c == "AT")
        {
            ll t;
            fin >> t;
            vector<ll> ans;
            auto st = chrono::steady_clock::now();
            atNode(root, t, ans);
            auto en = chrono::steady_clock::now();
            time_jog(atTime, chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            if (ans.empty())
            {
                fout << "none" << tata;
            }
            else
            {
                loop(i, 0, ans.size())
                {
                    if (i)
                    {
                        fout << " ";
                    }
                    fout << ans[i];
                }
                fout << tata;
            }
        }
        else if (c == "NEXT")
        {
            ll t;
            fin >> t;
            auto st = chrono::steady_clock::now();
            Node *ans = nextNode(t);
            auto en = chrono::steady_clock::now();
            time_jog(nextTime, chrono::duration_cast<chrono::nanoseconds>(en - st).count());
            if (ans == nullptr)
            {
                fout << "none" << tata;
            }
            else
            {
                fout << ans->id << " " << ans->start << " " << ans->end << tata;
            }
        }
    }
    cout << "operation,count,total_ns,average_ns" << tata;
    time_print("add", addTime);
    time_print("remove", removeTime);
    time_print("update", updateTime);
    time_print("conflict", conflictTime);
    time_print("overlaps", overlapsTime);
    time_print("at", atTime);
    time_print("next", nextTime);
    Tree_mucho(root);
    return 0;
}