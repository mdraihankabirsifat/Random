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
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

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
    // TODO
    return 0;
}

ll getMaxEnd(Node *node)
{
    // TODO: return LLONG_MIN for nullptr
    return LLONG_MIN;
}

void updateNode(Node *node)
{
    // TODO:
    // update node->height
    // update node->maxEnd = max(node->end, left maxEnd, right maxEnd)
}

ll Balance_dekhao(Node *node)
{
    // TODO
    return 0;
}

bool smaller(ll s1, ll id1, ll s2, ll id2)
{
    // TODO: lexicographic compare (start, id)
    return false;
}

Node *rotateLeft(Node *node)
{
    // TODO
    return node;
}

Node *rotateRight(Node *node)
{
    // TODO
    return node;
}

Node *rebalance(Node *node)
{
    // TODO: same AVL four cases
    // always keep BOTH height and maxEnd correct
    return node;
}

Node *insertNode(Node *node, ll id, ll start, ll end)
{
    // TODO: BST insert using (start, id), then rebalance
    return node;
}

Node *min_Node(Node *node)
{
    // TODO
    return node;
}

Node *eraseNode(Node *node, ll start, ll id)
{
    // TODO:
    // delete node identified by exact key (start, id)
    // if two children, copy successor's id/start/end
    // then delete successor and rebalance
    return node;
}

bool overlap(ll s1, ll e1, ll s2, ll e2)
{
    return s1 < e2 && s2 < e1;
}

bool conflictNode(Node *node, ll qs, ll qe)
{
    // TODO:
    // find any overlap using maxEnd pruning
    // target O(log n) expected/worst-case as intended by assignment
    return false;
}

void overlapsNode(Node *node, ll qs, ll qe, vector<ll> &ans)
{
    // TODO:
    // pruned inorder traversal
    // prune subtree when maxEnd <= qs
    // maintain increasing (start, id) reporting order
}

void atNode(Node *node, ll t, vector<ll> &ans)
{
    // TODO:
    // report all nodes where start <= t < end
    // use maxEnd pruning
    // inorder order
}

Node *nextNode(ll t)
{
    // TODO:
    // lower-bound search for smallest (start,id) with start >= t
    return nullptr;
}

string serialize(Node *node)
{
    // Same nested-parentheses format as AVL,
    // but node label is ONLY the event id.
    return "";
}

void Tree_mucho(Node *node)
{
    // TODO: postorder delete
}

struct TimingData
{
    ll count = 0,total_ns = 0;
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
            // TODO:
            // ll id = nextId++;
            // root = insertNode(root, id, s, e);
            // events[id] = {s, e};
            auto b = chrono::steady_clock::now();
            time_jog(addTime, chrono::duration_cast<chrono::nanoseconds>(b - a).count());
            fout << serialize(root) << tata;
        }
        else if (c == "REMOVE")
        {
            ll x;
            fin >> x;
            auto a = chrono::steady_clock::now();
            // TODO:
            // if id absent => not found
            // else remove (oldStart,id) from tree and erase hash entry
            bool y = false;
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
            // TODO:
            // absent id => not found and do not change nextId
            // otherwise erase old key, insert new interval with same id,
            // and update hash entry
            bool y = false;
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