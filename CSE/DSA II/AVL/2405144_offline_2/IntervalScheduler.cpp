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
    ll id, start, end;
    ll height, maxEnd;
    Node *left, *right;

    Node(ll _id, ll _start, ll _end)
    {
        id = _id;
        start = _start;
        end = _end;
        height = 1;
        maxEnd = _end;
        left = right = nullptr;
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

ll getBalance(Node *node)
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

Node *minimumNode(Node *node)
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
        cerr << "Usage: ./interval_scheduler <input-file> <output-file>" << tata;
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

    string cmd;

    while (fin >> cmd)
    {
        if (cmd == "ADD")
        {
            ll s, e;
            fin >> s >> e;

            auto st = chrono::steady_clock::now();

            // TODO:
            // ll id = nextId++;
            // root = insertNode(root, id, s, e);
            // events[id] = {s, e};

            auto en = chrono::steady_clock::now();

            addTiming(addTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            fout << serialize(root) << tata;
        }
        else if (cmd == "REMOVE")
        {
            ll id;
            fin >> id;

            auto st = chrono::steady_clock::now();

            // TODO:
            // if id absent => not found
            // else remove (oldStart,id) from tree and erase hash entry
            bool ok = false;

            auto en = chrono::steady_clock::now();

            addTiming(removeTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            if (!ok)
                fout << "not found" << tata;
            else
                fout << serialize(root) << tata;
        }
        else if (cmd == "UPDATE")
        {
            ll id, s, e;
            fin >> id >> s >> e;

            auto st = chrono::steady_clock::now();

            // TODO:
            // absent id => not found and do not change nextId
            // otherwise erase old key, insert new interval with same id,
            // and update hash entry
            bool ok = false;

            auto en = chrono::steady_clock::now();

            addTiming(updateTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            if (!ok)
                fout << "not found" << tata;
            else
                fout << serialize(root) << tata;
        }
        else if (cmd == "CONFLICT")
        {
            ll s, e;
            fin >> s >> e;

            auto st = chrono::steady_clock::now();
            bool ans = conflictNode(root, s, e);
            auto en = chrono::steady_clock::now();

            addTiming(conflictTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            fout << (ans ? "yes" : "no") << tata;
        }
        else if (cmd == "OVERLAPS")
        {
            ll s, e;
            fin >> s >> e;
            vector<ll> ans;

            auto st = chrono::steady_clock::now();
            overlapsNode(root, s, e, ans);
            auto en = chrono::steady_clock::now();

            addTiming(overlapsTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            if (ans.empty())
                fout << "none" << tata;
            else
            {
                loop(i, 0, ans.size())
                {
                    if (i)
                        fout << " ";
                    fout << ans[i];
                }
                fout << tata;
            }
        }
        else if (cmd == "AT")
        {
            ll t;
            fin >> t;
            vector<ll> ans;

            auto st = chrono::steady_clock::now();
            atNode(root, t, ans);
            auto en = chrono::steady_clock::now();

            addTiming(atTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            if (ans.empty())
                fout << "none" << tata;
            else
            {
                loop(i, 0, ans.size())
                {
                    if (i)
                        fout << " ";
                    fout << ans[i];
                }
                fout << tata;
            }
        }
        else if (cmd == "NEXT")
        {
            ll t;
            fin >> t;

            auto st = chrono::steady_clock::now();
            Node *ans = nextNode(t);
            auto en = chrono::steady_clock::now();

            addTiming(nextTime,
                      chrono::duration_cast<chrono::nanoseconds>(en - st).count());

            if (ans == nullptr)
                fout << "none" << tata;
            else
                fout << ans->id << " " << ans->start << " " << ans->end << tata;
        }
    }

    cout << "operation,count,total_ns,average_ns" << tata;
    printTiming("add", addTime);
    printTiming("remove", removeTime);
    printTiming("update", updateTime);
    printTiming("conflict", conflictTime);
    printTiming("overlaps", overlapsTime);
    printTiming("at", atTime);
    printTiming("next", nextTime);

    clearTree(root);
    return 0;
}