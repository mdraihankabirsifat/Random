#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
using ull = unsigned long long;
const ll size = 13;
const double MAX_LOAD = 0.50;
const double MIN_LOAD = 0.25;
const ll C1 = 1, C2 = 1;

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    if (n % 2 == 0)
        return n == 2;

    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

ll nextPrime(ll n)
{
    while (!isPrime(++n))
        ;
    return n;
}

ll previousPrime(ll n)
{
    while (!isPrime(n))
        n--;
    return n;
}

template <typename Key, typename Value>
class HashTable
{
private:
    struct Slot
    {
        Key key;
        Value value;
        int state = 0; // 0 = empty, 1 = occupied, 2 = deleted
    };

    vector<list<pair<Key, Value>>> chain;
    vector<Slot> table;
    ll tableSize = size;
    ll elements = 0;
    ll collisions = 0;
    ll insertedAfterExpansion = 0;
    ll deletedAfterCompaction = 0;
    int hashNumber;
    int method; // 0 = chaining, 1 = double hashing, 2 = custom probing

    string text(const Key &key) const
    {
        stringstream ss;
        ss << key;
        return ss.str();
    }

    // Hash1 = DJB2, Hash2 = SDBM.
    ull hash1(const string &s) const
    {
        ull h = 5381;
        for (unsigned char c : s)
            h = h * 33 + c;
        return h;
    }

    ull hash2(const string &s) const
    {
        ull h = 0;
        for (unsigned char c : s)
            h = c + (h << 6) + (h << 16) - h;
        return h;
    }

    ull auxHash(const string &s) const
    {
        ull h = 0;
        for (unsigned char c : s)
            h = h * 37 + c;
        return 1 + h % (tableSize - 1);
    }

    ll primaryHash(const Key &key) const
    {
        string s = text(key);
        return (hashNumber == 1 ? hash1(s) : hash2(s)) % tableSize;
    }

    // Probe formula is selected by the method.
    ll probe(const Key &key, ll i) const
    {
        ull h = primaryHash(key);
        ull step = auxHash(text(key));

        if (method == 1)
            return (h + i * step) % tableSize;

        return (h + C1 * i * step + C2 * i * i) % tableSize;
    }

    void Table_banao()
    {
        chain.clear();
        table.clear();
        if (method == 0)
        {
            chain.resize(tableSize);
        }
        else
        {
            table.resize(tableSize);
        }
    }

    // Rehashing must not change collision/operation counters.
    void place(const Key &key, const Value &value)
    {
        if (method == 0)
        {
            chain[primaryHash(key)].push_back({key, value});
            return;
        }

        loop(i, 0, tableSize)
        {
            ll index = probe(key, i);
            if (table[index].state != 1)
            {
                table[index] = {key, value, 1};
                return;
            }
        }
    }

    void rehash(ll newSize)
    {
        vector<pair<Key, Value>> items;

        if (method == 0)
        {
            for (auto &bucket : chain)
                for (auto &item : bucket)
                    items.pb(item);
        }
        else
        {
            for (auto &slot : table)
                if (slot.state == 1)
                    items.pb({slot.key, slot.value});
        }

        tableSize = newSize;
        Table_banao();

        for (auto &item : items)
            place(item.first, item.second);
    }

    void checkExpansion()
    {
        ll need = (elements + 1) / 2;

        if ((double)elements / tableSize > MAX_LOAD &&
            insertedAfterExpansion >= need)
        {
            rehash(nextPrime(2 * tableSize));
            insertedAfterExpansion = 0;
        }
    }

    void checkCompaction()
    {
        ll need = (elements + 1) / 2;

        if (tableSize != size &&
            (double)elements / tableSize < MIN_LOAD &&
            deletedAfterCompaction >= need)
        {
            ll newSize = max(size, previousPrime(tableSize / 2));
            rehash(newSize);
            deletedAfterCompaction = 0;
        }
    }

public:
    HashTable(int selectedMethod, int selectedHash)
    {
        method = selectedMethod;
        hashNumber = selectedHash;
        Table_banao();
    }

    bool insert(const Key &key, const Value &value)
    {
        if (method == 0)
        {
            ll index = primaryHash(key);

            for (auto &item : chain[index])
            {
                if (item.first == key)
                {
                    item.second = value;
                    return false;
                }
            }

            collisions += chain[index].size();
            chain[index].push_back({key, value});
        }
        else
        {
            ll deletedIndex = -1;

            loop(i, 0, tableSize)
            {
                ll index = probe(key, i);

                if (table[index].state == 1)
                {
                    if (table[index].key == key)
                    {
                        table[index].value = value;
                        return false;
                    }
                    collisions++;
                }
                else if (table[index].state == 2)
                {
                    if (deletedIndex == -1)
                        deletedIndex = index;
                }
                else
                {
                    if (deletedIndex != -1)
                        index = deletedIndex;
                    table[index] = {key, value, 1};
                    break;
                }
            }
        }

        elements++;
        insertedAfterExpansion++;
        checkExpansion();
        return true;
    }

    bool search(const Key &key, Value &value, ll &hits) const
    {
        hits = 0;

        if (method == 0)
        {
            for (auto &item : chain[primaryHash(key)])
            {
                hits++;
                if (item.first == key)
                {
                    value = item.second;
                    return true;
                }
            }
            return false;
        }

        loop(i, 0, tableSize)
        {
            ll index = probe(key, i);
            hits++;

            if (table[index].state == 0)
                return false;

            if (table[index].state == 1 && table[index].key == key)
            {
                value = table[index].value;
                return true;
            }
        }
        return false;
    }

    bool erase(const Key &key)
    {
        if (method == 0)
        {
            ll index = primaryHash(key);

            for (auto it = chain[index].begin(); it != chain[index].end(); it++)
            {
                if (it->first == key)
                {
                    chain[index].erase(it);
                    elements--;
                    deletedAfterCompaction++;
                    checkCompaction();
                    return true;
                }
            }
            return false;
        }

        loop(i, 0, tableSize)
        {
            ll index = probe(key, i);

            if (table[index].state == 0)
                return false;

            if (table[index].state == 1 && table[index].key == key)
            {
                table[index].state = 2; // Tombstone keeps probe path valid.
                elements--;
                deletedAfterCompaction++;
                checkCompaction();
                return true;
            }
        }
        return false;
    }

    ll collisionCount() const
    {
        return collisions;
    }
};

vector<string> generateWords(ll total, ll length)
{
    const string letters = "abcdefghijklmnopqrstuvwxyz";
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> randomLetter(0, 25);
    unordered_set<string> used;
    vector<string> words;
    while ((ll)words.size() < total)
    {
        string word;
        loop(i, 0, length)
        {
            word += letters[randomLetter(rng)];
        }
        if (used.insert(word).second)
        {
            words.pb(word);
        }
    }
    return words;
}

struct Result
{
    ll collisions;
    double averageHits;
};

Result runExperiment(int method, int hashNumber, const vector<string> &words, const vector<ll> &sample)
{
    HashTable<string, ll> hashTable(method, hashNumber);

    loop(i, 0, (ll)words.size())
        hashTable.insert(words[i], i + 1);

    ll totalHits = 0, value;
    for (ll index : sample)
    {
        ll hits;
        hashTable.search(words[index], value, hits);
        totalHits += hits;
    }

    return {hashTable.collisionCount(), (double)totalHits / sample.size()};
}

void printReport(Result ans[3][2])
{
    vector<string> s = {"Chaining Method", "Double Hashing", "Custom Probing"};
    cout << left << setw(20) << "Method"
         << setw(18) << "Hash1 Collision"
         << setw(15) << "Hash1 Hits"
         << setw(18) << "Hash2 Collision"
         << "Hash2 Hits" << tata;
    cout << fixed << setprecision(3);
    loop(i, 0, 3)
    {
        cout << setw(20) << s[i]
             << setw(18) << ans[i][0].collisions
             << setw(15) << ans[i][0].averageHits
             << setw(18) << ans[i][1].collisions
             << ans[i][1].averageHits << tata;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const ll TOTAL_WORDS = 10000;
    const ll TOTAL_SEARCHES = 1000;
    ll l;
    cin >> l; // Enter 10 for the required report.
    if (l < 3)
    {
        cout << "Length must be at least 3 for 10000 unique words." << tata;
        return 0;
    }
    vector<string> words = generateWords(TOTAL_WORDS, l);
    vector<ll> indices(TOTAL_WORDS);
    iota(indices.begin(), indices.end(), 0);
    shuffle(indices.begin(), indices.end(), mt19937(random_device{}()));
    vector<ll> sample(indices.begin(), indices.begin() + TOTAL_SEARCHES);
    Result ans[3][2];
    loop(method, 0, 3)
    {
        loop(hashNumber, 1, 3)
        {
            ans[method][hashNumber - 1] = runExperiment(method, hashNumber, words, sample);
        }
    }
    printReport(ans);
    return 0;
}
