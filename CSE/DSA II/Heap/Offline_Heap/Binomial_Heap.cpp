#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
struct Node
{
    ll key, degree;
    Node *parent, *child, *sibling;
    Node(ll x)
    {
        key = x;
        degree = 0;
        parent = child = sibling = NULL;
    }
};
class BinomialHeap
{
public:
    Node *head;
    ll heapSize;
    unordered_map<ll, Node *> position;
    BinomialHeap()
    {
        head = NULL;
        heapSize = 0;
    }
    void linkTree(Node *child, Node *parent)
    {
        child->parent = parent;
        child->sibling = parent->child;
        parent->child = child;
        parent->degree++;
    }
    Node *mergeRootLists(Node *a, Node *b)
    {
        Node d(0), *tail = &d;
        while (a && b)
        {
            if (a->degree <= b->degree)
            {
                tail->sibling = a;
                a = a->sibling;
            }
            else
            {
                tail->sibling = b;
                b = b->sibling;
            }
            tail = tail->sibling;
        }
        tail->sibling = a ? a : b;
        return d.sibling;
    }
    void consolidate(bool show = false)
    {
        if (!head)
        {
            return;
        }
        Node *previous = NULL;
        Node *cur = head;
        Node *next = cur->sibling;
        while (next)
        {
            if (cur->degree != next->degree || (next->sibling && next->sibling->degree == cur->degree))
            {
                previous = cur;
                cur = next;
            }
            else if (cur->key <= next->key)
            {
                if (show)
                {
                    cout << "Link: B" << cur->degree << " + B" << next->degree << " -> B" << cur->degree + 1 << tata;
                }
                cur->sibling = next->sibling;
                linkTree(next, cur);
            }
            else
            {
                if (show)
                {
                    cout << "Link: B" << cur->degree << " + B" << next->degree << " -> B" << cur->degree + 1 << tata;
                }
                if (!previous)
                {
                    head = next;
                }
                else
                {
                    previous->sibling = next;
                }
                linkTree(cur, next);
                cur = next;
            }
            next = cur->sibling;
        }
    }
    void unite(BinomialHeap &other, bool show = false)
    {
        head = mergeRootLists(head, other.head);
        heapSize += other.heapSize;
        for (auto p : other.position)
        {
            position[p.first] = p.second;
        }
        other.head = NULL;
        other.heapSize = 0;
        other.position.clear();
        consolidate(show);
    }
    void insertKey(ll key)
    {
        BinomialHeap one;
        one.head = new Node(key);
        one.heapSize = 1;
        one.position[key] = one.head;
        unite(one);
    }
    ll findMin()
    {
        ll answer = LLONG_MAX;
        for (Node *root = head; root; root = root->sibling)
        {
            answer = min(answer, root->key);
        }
        return answer;
    }
    ll extractMin()
    {
        Node *minimum = head, *minimumPrevious = NULL;
        Node *previous = NULL;
        for (Node *root = head; root; root = root->sibling)
        {
            if (root->key < minimum->key)
            {
                minimum = root;
                minimumPrevious = previous;
            }
            previous = root;
        }
        if (!minimumPrevious)
        {
            head = minimum->sibling;
        }
        else
        {
            minimumPrevious->sibling = minimum->sibling;
        }
        Node *children = NULL;
        Node *child = minimum->child;
        while (child)
        {
            Node *next = child->sibling;
            child->parent = NULL;
            child->sibling = children;
            children = child;
            child = next;
        }
        BinomialHeap childHeap;
        childHeap.head = children;
        head = mergeRootLists(head, childHeap.head);
        consolidate();
        ll answer = minimum->key;
        position.erase(answer);
        heapSize--;
        delete minimum;
        return answer;
    }
    void decreaseKey(ll oldKey, ll newKey)
    {
        Node *cur = position[oldKey];
        position.erase(oldKey);
        cur->key = newKey;
        position[newKey] = cur;
        while (cur->parent && cur->key < cur->parent->key)
        {
            Node *parent = cur->parent;
            swap(cur->key, parent->key);
            position[cur->key] = cur;
            position[parent->key] = parent;
            cur = parent;
        }
    }
    void removeKey(ll key)
    {
        decreaseKey(key, LLONG_MIN);
        extractMin();
    }
    void printHeap(ll heapNumber, ostream &out)
    {
        out << "Printing Binomial Heap H" << heapNumber << tata;
        out << "Heap size: " << heapSize << tata;
        if (!head)
        {
            out << "Heap H" << heapNumber << " is empty." << tata;
            return;
        }
        for (Node *root = head; root; root = root->sibling)
        {
            out << "Binomial Tree, B" << root->degree << tata;
            queue<Node *> q;
            q.push(root);
            ll level = 0;
            while (!q.empty())
            {
                ll n = q.size();
                vector<ll> keys;
                while (n--)
                {
                    Node *cur = q.front();
                    q.pop();
                    keys.pb(cur->key);
                    for (Node *child = cur->child; child; child = child->sibling)
                    {
                        q.push(child);
                    }
                }
                sort(keys.begin(), keys.end());
                out << "Level " << level++ << ":";
                for (ll key : keys)
                {
                    out << " " << key;
                }
                out << tata;
            }
        }
    }
    void drawTree(Node *node, string space, bool last, ll minimum)
    {
        cout << space << (last ? "`-- " : "|-- ") << node->key;
        if (node->key == minimum)
        {
            cout << " [MIN]";
        }
        cout << " (degree " << node->degree << ")" << tata;
        vector<Node *> children;
        for (Node *child = node->child; child; child = child->sibling)
        {
            children.pb(child);
        }
        loop(i, 0, (ll)children.size())
        {
            drawTree(children[i], space + (last ? "    " : "|   "), i + 1 == (ll)children.size(), minimum);
        }
    }
    void visualize(ll heapNumber)
    {
        cout << "Visualizing Heap H" << heapNumber << tata;
        cout << "Heap size: " << heapSize << tata;
        if (!head)
        {
            cout << "Heap H" << heapNumber << " is empty." << tata;
            return;
        }
        ll minimum = findMin();
        for (Node *root = head; root; root = root->sibling)
        {
            cout << "B" << root->degree << ", root = " << root->key << tata;
            drawTree(root, "", true, minimum);
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream input("input.txt");
    ofstream output("output.txt");
    BinomialHeap heap[3];
    string command;
    while (input >> command)
    {
        if (command == "I")
        {
            ll h, x;
            input >> h >> x;
            heap[h].insertKey(x);
        }
        else if (command == "F")
        {
            ll h;
            input >> h;
            ll answer = heap[h].findMin();
            cout << "Find Min returned: " << answer << tata;
            output << "Find Min returned: " << answer << tata;
        }
        else if (command == "E")
        {
            ll h;
            input >> h;
            ll answer = heap[h].extractMin();
            cout << "Extract Min returned: " << answer << tata;
            output << "Extract Min returned: " << answer << tata;
        }
        else if (command == "D")
        {
            ll h, x, y;
            input >> h >> x >> y;
            heap[h].decreaseKey(x, y);
        }
        else if (command == "R")
        {
            ll h, x;
            input >> h >> x;
            heap[h].removeKey(x);
        }
        else if (command == "U")
        {
            ll h1, h2;
            input >> h1 >> h2;
            heap[h1].unite(heap[h2]);
        }
        else if (command == "P")
        {
            ll h;
            input >> h;
            heap[h].printHeap(h, cout);
            heap[h].printHeap(h, output);
        }
        else if (command == "V")
        {
            ll h;
            input >> h;
            heap[h].visualize(h);
        }
        else if (command == "W")
        {
            ll h1, h2;
            input >> h1 >> h2;
            cout << "Before Union" << tata;
            heap[h1].visualize(h1);
            heap[h2].visualize(h2);
            cout << "Union Steps" << tata;
            heap[h1].unite(heap[h2], true);
            cout << "After Union" << tata;
            heap[h1].visualize(h1);
        }
    }
    return 0;
}