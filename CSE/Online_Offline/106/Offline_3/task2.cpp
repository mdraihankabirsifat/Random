#include <iostream>
#include <fstream>
#include <string>
#include "listBST.hpp"
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file)
    {
        cerr << "Unable to open file\n";
        return 1;
    }

    // TODO: Declare data structures to track bid statistics for each item
    // You need to track: total bids, successful bids, rejected bids for each item
    // Hint: You may use additional BSTs or other data structures
    // Start your code here
    struct ItemInfo
    {
        int bid, t = 0, s = 0, r = 0;

        // FIX: Use a static function to hold state (allowed in local classes)
        static bool &report()
        {
            static bool val = false;
            return val;
        }

        ItemInfo(int b = 0) : bid(b) {}

        // Inline friend definition is required for local classes
        friend ostream &operator<<(ostream &os, const ItemInfo &i)
        {
            if (report())
                os << "Current bid: " << i.bid << ", Total bids: " << i.t
                   << ", Successful: " << i.s << ", Rejected: " << i.r;
            else
                os << i.bid;
            return os;
        }
    };

    int g_bids = 0, g_succ = 0, g_rej = 0;
    ListBST<string, ItemInfo> *bst = new ListBST<string, ItemInfo>();
    // End your code here

    int n;
    in_file >> n;
    for (int i = 0; i < n; ++i)
    {
        // TODO: Implement the logic to read initial items and their starting bids
        // Initialize statistics tracking for each item
        // Start your code here
        string id;
        int b;
        in_file >> id >> b;
        bst->insert(id, ItemInfo(b));
        // End your code here
    }

    // TODO: Implement the logic to print the initial auction state
    // Start your code here
    cout << "Initial auction items:" << endl;
    ItemInfo::report() = false;
    bst->print('I');
    // End your code here
    cout << "\nAuction starts!\n\n";
    cout << "==============================\n";

    string operation;
    while (in_file >> operation)
    {
        // TODO: Implement the logic to process operations (ADD, BID, CHECK, STATS, REPORT) and print auction state after each operation
        // For BID operations: update statistics (total bids, successful/rejected counts)
        // For STATS operations: display statistics for the specified item
        // For REPORT operations: display comprehensive auction statistics
        // For other operations: print auction state using in-order traversal
        // Start your code here
        string id;
        int val;

        if (operation == "ADD")
        {
            in_file >> id >> val;
            if (bst->find(id))
            {
                ItemInfo s = bst->get(id);
                if (val > s.bid)
                {
                    s.bid = val;
                    bst->update(id, s);
                }
            }
            else
                bst->insert(id, ItemInfo(val));
            cout << "Item " << id << " added with starting bid " << val << endl;
            ItemInfo::report() = false;
            bst->print('I');
        }
        else if (operation == "BID")
        {
            in_file >> id >> val;
            g_bids++;
            if (!bst->find(id))
            {
                cout << "Bid rejected. Item " << id << " not found." << endl;
                g_rej++;
            }
            else
            {
                ItemInfo s = bst->get(id);
                s.t++;
                if (val > s.bid)
                {
                    s.bid = val;
                    s.s++;
                    g_succ++;
                    cout << "Bid of " << val << " on " << id << " accepted. Current bid: " << val << endl;
                }
                else
                {
                    s.r++;
                    g_rej++;
                    cout << "Bid of " << val << " on " << id << " rejected. Current bid: " << s.bid << endl;
                }
                bst->update(id, s);
            }
            ItemInfo::report() = false;
            bst->print('I');
        }
        else if (operation == "CHECK")
        {
            in_file >> id;
            if (bst->find(id))
                cout << "Current bid for " << id << ": " << bst->get(id).bid << endl;
            else
                cout << "Item " << id << " not found." << endl;
            ItemInfo::report() = false;
            bst->print('I');
        }
        else if (operation == "STATS")
        {
            in_file >> id;
            if (bst->find(id))
            {
                ItemInfo s = bst->get(id);
                cout << "Statistics for " << id << ":" << endl;
                cout << "  Current highest bid: " << s.bid << "\n  Total bids placed: " << s.t
                     << "\n  Successful bids: " << s.s << "\n  Rejected bids: " << s.r << endl;
            }
            else
                cout << "Item " << id << " not found." << endl;
        }
        else if (operation == "REPORT")
        {
            cout << "Auction Report:\nTotal items: " << bst->size() << "\nTotal bids placed: " << g_bids
                 << "\nTotal successful bids: " << g_succ << "\nTotal rejected bids: " << g_rej
                 << "\n\nItem Statistics:" << endl;
            ItemInfo::report() = true;
            bst->print('R');
            ItemInfo::report() = false;
        }
        // End your code here
        cout << "==============================\n";
    }

    in_file.close();
    // TODO: Delete data structures you created
    // Start your code here
    delete bst;
    // End your code here
    return 0;
}