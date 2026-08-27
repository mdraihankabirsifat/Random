#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
using ull = unsigned long long;
using uc = unsigned char;
const ll INITIAL_SIZE = 13;
const double MAX_LOAD = 0.50;
const double MIN_LOAD = 0.25;
const ll C1 = 1, C2 = 1;
bool isPrime(ll n)
{
    if (n < 2)
    {
        return false;
    }
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
ll porer_prime(ll n)
{
    n++;
    while (!isPrime(n))
    {
        n++;
    }
    return n;
}
ll ager_prime(ll n)
{
    n--;
    while (!isPrime(n))
    {
        n--;
    }
    return n;
}
template <typename Key>
string key_theke_string(const Key &key)
{
    stringstream ss;
    ss << key;
    return ss.str();
}
// Two standard hash functions: DJB2 and SDBM.
ull h1(const string &s)
{
    ull h = 5381;
    for (uc c : s)
    {
        h = h * 33 + c;
    }
    return h;
}
ull h2(const string &s)
{
    ull h = 0;
    for (uc c : s)
    {
        h = c + (h << 6) + (h << 16) - h;
    }
    return h;
}
template <typename Key>
ll pri_hash(const Key &key, int hash_Num, ll sz)
{
    string s = key_theke_string(key);
    return (hash_Num == 1 ? h1(s) : h2(s)) % sz;
}
ull aux_Hash(const string &s, ll sz)
{
    ull h = 0;
    for (uc c : s)
    {
        h = h * 37 + c;
    }
    // For a prime table size, every value from 1 to N-1 is coprime with N.
    return 1 + h % (sz - 1);
}
// ------------------------------------------------------------
// 1. Separate Chaining
// ------------------------------------------------------------
template <typename Key, typename Value>
class ChainingHashTable
{
private:
    vector<list<pair<Key, Value>>> tb;
    ll sz = INITIAL_SIZE, elmnt = 0, cols = 0, insertedAfterExpansion = 0, deletedAfterCompaction = 0;
    int hashNumber;
    ll getIndex(const Key &key) const
    {
        return pri_hash(key, hashNumber, sz);
    }
    // Rehashing moves old items without counting new collisions.
    void rehash(ll newSize)
    {
        vector<pair<Key, Value>> items;
        for (auto &b : tb)
        {
            for (auto &item : b)
            {
                items.pb(item);
            }
        }
        sz = newSize;
        tb.clear();
        tb.resize(sz);
        for (auto &item : items)
        {
            tb[getIndex(item.first)].push_back(item);
        }
    }
    void checkExpansion()
    {
        ll need = (elmnt + 1) / 2;
        if ((double)elmnt / sz > MAX_LOAD &&
            insertedAfterExpansion >= need)
        {
            rehash(porer_prime(2 * sz));
            insertedAfterExpansion = 0;
        }
    }
    void checkCompaction()
    {
        ll need = (elmnt + 1) / 2;
        if (sz != INITIAL_SIZE &&
            (double)elmnt / sz < MIN_LOAD &&
            deletedAfterCompaction >= need)
        {
            ll newSize = max(INITIAL_SIZE, ager_prime(sz / 2));
            rehash(newSize);
            deletedAfterCompaction = 0;
        }
    }

public:
    ChainingHashTable(int selectedHash)
    {
        hashNumber = selectedHash;
        tb.resize(sz);
    }
    bool insert(const Key &key, const Value &value)
    {
        ll index = getIndex(key);
        for (auto &item : tb[index])
        {
            if (item.first == key)
            {
                item.second = value;
                return false;
            }
        }
        // Every old item in this bucket collides with the new key.
        cols += tb[index].size();
        tb[index].push_back({key, value});
        elmnt++;
        insertedAfterExpansion++;
        checkExpansion();
        return true;
    }
    bool search(const Key &key, Value &value, ll &hits) const
    {
        hits = 0;
        for (auto &item : tb[getIndex(key)])
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
    bool erase(const Key &key)
    {
        ll index = getIndex(key);
        for (auto it = tb[index].begin(); it != tb[index].end(); it++)
        {
            if (it->first == key)
            {
                tb[index].erase(it);
                elmnt--;
                deletedAfterCompaction++;
                checkCompaction();
                return true;
            }
        }
        return false;
    }
    ll collisionCount() const
    {
        return cols;
    }
};
// ------------------------------------------------------------
// 2. Double Hashing
// ------------------------------------------------------------
template <typename Key, typename Value>
class DoubleHashTable
{
private:
    vector<pair<Key, Value>> table;
    vector<int> state; // 0 = empty, 1 = occupied, 2 = deleted
    ll sz = INITIAL_SIZE;
    ll elements = 0;
    ll collisions = 0;
    ll insertedAfterExpansion = 0;
    ll deletedAfterCompaction = 0;
    int hashNumber;
    ll probe(const Key &key, ll i) const
    {
        ull h = pri_hash(key, hashNumber, sz);
        ull step = aux_Hash(key_theke_string(key), sz);
        return (h + i * step) % sz;
    }
    void makeTable()
    {
        table.clear();
        table.resize(sz);
        state.assign(sz, 0);
    }
    void place(const Key &key, const Value &value)
    {
        loop(i, 0, sz)
        {
            ll index = probe(key, i);
            if (state[index] != 1)
            {
                table[index] = {key, value};
                state[index] = 1;
                return;
            }
        }
    }
    // Rehashing removes tombstones and recomputes every index.
    void rehash(ll newSize)
    {
        vector<pair<Key, Value>> items;
        loop(i, 0, sz)
        {
            if (state[i] == 1)
            {
                items.pb(table[i]);
            }
        }
        sz = newSize;
        makeTable();
        for (auto &item : items)
        {
            place(item.first, item.second);
        }
    }
    void checkExpansion()
    {
        ll need = (elements + 1) / 2;
        if ((double)elements / sz > MAX_LOAD &&
            insertedAfterExpansion >= need)
        {
            rehash(porer_prime(2 * sz));
            insertedAfterExpansion = 0;
        }
    }
    void checkCompaction()
    {
        ll need = (elements + 1) / 2;
        if (sz != INITIAL_SIZE &&
            (double)elements / sz < MIN_LOAD &&
            deletedAfterCompaction >= need)
        {
            ll newSize = max(INITIAL_SIZE, ager_prime(sz / 2));
            rehash(newSize);
            deletedAfterCompaction = 0;
        }
    }

public:
    DoubleHashTable(int selectedHash)
    {
        hashNumber = selectedHash;
        makeTable();
    }
    bool insert(const Key &key, const Value &value)
    {
        ll deletedIndex = -1;
        loop(i, 0, sz)
        {
            ll index = probe(key, i);
            if (state[index] == 1)
            {
                if (table[index].first == key)
                {
                    table[index].second = value;
                    return false;
                }
                collisions++;
            }
            else if (state[index] == 2)
            {
                if (deletedIndex == -1)
                {
                    deletedIndex = index;
                }
            }
            else
            {
                if (deletedIndex != -1)
                {
                    index = deletedIndex;
                }
                table[index] = {key, value};
                state[index] = 1;
                elements++;
                insertedAfterExpansion++;
                checkExpansion();
                return true;
            }
        }
        // This is used only when the probe saw a tombstone but no empty slot.
        if (deletedIndex != -1)
        {
            table[deletedIndex] = {key, value};
            state[deletedIndex] = 1;
            elements++;
            insertedAfterExpansion++;
            checkExpansion();
            return true;
        }
        return false;
    }
    bool search(const Key &key, Value &value, ll &hits) const
    {
        hits = 0;
        loop(i, 0, sz)
        {
            ll index = probe(key, i);
            hits++;
            if (state[index] == 0)
            {
                return false;
            }
            if (state[index] == 1 && table[index].first == key)
            {
                value = table[index].second;
                return true;
            }
        }
        return false;
    }
    bool erase(const Key &key)
    {
        loop(i, 0, sz)
        {
            ll index = probe(key, i);
            if (state[index] == 0)
            {
                return false;
            }
            if (state[index] == 1 && table[index].first == key)
            {
                // A tombstone keeps the probe path valid for later searches.
                state[index] = 2;
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
// ------------------------------------------------------------
// 3. Custom Probing
// ------------------------------------------------------------
template <typename Key, typename Value>
class CustomHashTable
{
private:
    vector<pair<Key, Value>> table;
    vector<int> state; // 0 = empty, 1 = occupied, 2 = deleted
    ll sz = INITIAL_SIZE;
    ll elements = 0;
    ll collisions = 0;
    ll insertedAfterExpansion = 0;
    ll deletedAfterCompaction = 0;
    int hashNumber;
    ll probe(const Key &key, ll i) const
    {
        ull h = pri_hash(key, hashNumber, sz);
        ull step = aux_Hash(key_theke_string(key), sz);
        return (h + C1 * i * step + C2 * i * i) % sz;
    }
    void makeTable()
    {
        table.clear();
        table.resize(sz);
        state.assign(sz, 0);
    }
    void place(const Key &key, const Value &value)
    {
        loop(i, 0, sz)
        {
            ll index = probe(key, i);
            if (state[index] != 1)
            {
                table[index] = {key, value};
                state[index] = 1;
                return;
            }
        }
    }
    void rehash(ll newSize)
    {
        vector<pair<Key, Value>> items;
        loop(i, 0, sz)
        {
            if (state[i] == 1)
            {
                items.pb(table[i]);
            }
        }
        sz = newSize;
        makeTable();
        for (auto &item : items)
        {
            place(item.first, item.second);
        }
    }
    void checkExpansion()
    {
        ll need = (elements + 1) / 2;
        if ((double)elements / sz > MAX_LOAD &&
            insertedAfterExpansion >= need)
        {
            rehash(porer_prime(2 * sz));
            insertedAfterExpansion = 0;
        }
    }
    void checkCompaction()
    {
        ll need = (elements + 1) / 2;
        if (sz != INITIAL_SIZE &&
            (double)elements / sz < MIN_LOAD &&
            deletedAfterCompaction >= need)
        {
            ll newSize = max(INITIAL_SIZE, ager_prime(sz / 2));
            rehash(newSize);
            deletedAfterCompaction = 0;
        }
    }

public:
    CustomHashTable(int selectedHash)
    {
        hashNumber = selectedHash;
        makeTable();
    }
    bool insert(const Key &key, const Value &value)
    {
        ll deletedIndex = -1;
        loop(i, 0, sz)
        {
            ll index = probe(key, i);
            if (state[index] == 1)
            {
                if (table[index].first == key)
                {
                    table[index].second = value;
                    return false;
                }
                collisions++;
            }
            else if (state[index] == 2)
            {
                if (deletedIndex == -1)
                {
                    deletedIndex = index;
                }
            }
            else
            {
                if (deletedIndex != -1)
                {
                    index = deletedIndex;
                }
                table[index] = {key, value};
                state[index] = 1;
                elements++;
                insertedAfterExpansion++;
                checkExpansion();
                return true;
            }
        }
        if (deletedIndex != -1)
        {
            table[deletedIndex] = {key, value};
            state[deletedIndex] = 1;
            elements++;
            insertedAfterExpansion++;
            checkExpansion();
            return true;
        }
        return false;
    }
    bool search(const Key &key, Value &value, ll &hits) const
    {
        hits = 0;
        loop(i, 0, sz)
        {
            ll index = probe(key, i);
            hits++;
            if (state[index] == 0)
            {
                return false;
            }
            if (state[index] == 1 && table[index].first == key)
            {
                value = table[index].second;
                return true;
            }
        }
        return false;
    }
    bool erase(const Key &key)
    {
        loop(i, 0, sz)
        {
            ll index = probe(key, i);
            if (state[index] == 0)
            {
                return false;
            }
            if (state[index] == 1 && table[index].first == key)
            {
                state[index] = 2;
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
vector<string> Word_banao(ll total, ll length)
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
        // unordered_set::insert returns false when the word is a duplicate.
        if (used.insert(word).second)
        {
            words.pb(word);
        }
    }
    return words;
}
using Result = pair<ll, double>; // {collisions, average hits}
// The same experiment works for each of the three hash-table classes.
template <typename Table>
Result Exp_chalao(int hashNumber, const vector<string> &words, const vector<ll> &sample)
{
    Table hashTable(hashNumber);
    loop(i, 0, (ll)words.size())
    {
        hashTable.insert(words[i], i + 1);
    }
    ll totalHits = 0, value;
    for (ll index : sample)
    {
        ll hits;
        hashTable.search(words[index], value, hits);
        totalHits += hits;
    }
    return {hashTable.collisionCount(), (double)totalHits / sample.size()};
}
void dekhao(Result ans[3][2])
{
    vector<string> names = {
        "Chaining Method", "Double Hashing", "Custom Probing"};
    cout << left << setw(20) << "Method"
         << setw(18) << "Hash1 Collision"
         << setw(15) << "Hash1 Hits"
         << setw(18) << "Hash2 Collision"
         << "Hash2 Hits" << tata;
    cout << fixed << setprecision(3);
    loop(i, 0, 3)
    {
        cout << setw(20) << names[i]
             << setw(18) << ans[i][0].first
             << setw(15) << ans[i][0].second
             << setw(18) << ans[i][1].first
             << ans[i][1].second << tata;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll w = 10000, search = 1000, l;
    cin >> l; // Enter 10 for the assignment report.
    if (l < 3)
    {
        cout << "Length must be at least 3 for 10000 unique words." << tata;
        return 0;
    }
    vector<string> words = Word_banao(w, l);
    // Shuffle indices, then use the first 1000 as successful search samples.
    vector<ll> id(w);
    iota(id.begin(), id.end(), 0);
    shuffle(id.begin(), id.end(), mt19937(random_device{}()));
    vector<ll> sample(id.begin(), id.begin() + search);
    Result ans[3][2];
    loop(hashNumber, 1, 3)
    {
        ans[0][hashNumber - 1] = Exp_chalao<ChainingHashTable<string, ll>>(hashNumber, words, sample);
        ans[1][hashNumber - 1] = Exp_chalao<DoubleHashTable<string, ll>>(hashNumber, words, sample);
        ans[2][hashNumber - 1] = Exp_chalao<CustomHashTable<string, ll>>(hashNumber, words, sample);
    }
    dekhao(ans);
    return 0;
}
