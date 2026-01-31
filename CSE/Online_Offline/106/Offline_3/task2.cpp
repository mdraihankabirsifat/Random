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

    // TODO: Declare data structures...
    ListBST<string, int> *priceTree = new ListBST<string, int>();
    ListBST<string, int> *totalTree = new ListBST<string, int>();
    ListBST<string, int> *successTree = new ListBST<string, int>();
    ListBST<string, int> *rejectTree = new ListBST<string, int>();

    int g_bids = 0, g_succ = 0, g_rej = 0;

    // Link trees
    ListBST<string, int>::T_Total = totalTree;
    ListBST<string, int>::T_Success = successTree;
    ListBST<string, int>::T_Reject = rejectTree;
    // End your code here

    int n;
    in_file >> n;
    for (int i = 0; i < n; ++i)
    {
        // TODO: Read initial items...
        string id;
        int b;
        in_file >> id >> b;
        priceTree->insert(id, b);
        totalTree->insert(id, 0);
        successTree->insert(id, 0);
        rejectTree->insert(id, 0);
        // End your code here
    }

    // TODO: Print initial state...
    cout << "Initial auction items:" << endl;
    priceTree->print('I');
    // End your code here
    cout << "\nAuction starts!\n\n";
    cout << "==============================\n";

    string operation;
    while (in_file >> operation)
    {
        // TODO: Process operations...
        string id;
        int val;

        if (operation == "ADD")
        {
            in_file >> id >> val;
            if (priceTree->find(id))
            {
                if (val > priceTree->get(id))
                    priceTree->update(id, val);
            }
            else
            {
                priceTree->insert(id, val);
                totalTree->insert(id, 0);
                successTree->insert(id, 0);
                rejectTree->insert(id, 0);
            }
            cout << "Item " << id << " added with starting bid " << val << endl;
            priceTree->print('I');
        }
        else if (operation == "BID")
        {
            in_file >> id >> val;
            g_bids++;
            if (!priceTree->find(id))
            {
                g_rej++;
                cout << "Bid rejected. Item " << id << " not found." << endl;
            }
            else
            {
                totalTree->update(id, totalTree->get(id) + 1);
                if (val > priceTree->get(id))
                {
                    g_succ++;
                    priceTree->update(id, val);
                    successTree->update(id, successTree->get(id) + 1);
                    cout << "Bid of " << val << " on " << id << " accepted. Current bid: " << val << endl;
                }
                else
                {
                    g_rej++;
                    rejectTree->update(id, rejectTree->get(id) + 1);
                    cout << "Bid of " << val << " on " << id << " rejected. Current bid: " << priceTree->get(id) << endl;
                }
            }
            priceTree->print('I');
        }
        else if (operation == "CHECK")
        {
            in_file >> id;
            if (priceTree->find(id))
                cout << "Current bid for " << id << ": " << priceTree->get(id) << endl;
            else
                cout << "Item " << id << " not found." << endl;
            priceTree->print('I');
        }
        else if (operation == "STATS")
        {
            in_file >> id;
            if (priceTree->find(id))
            {
                cout << "Statistics for " << id << ":" << endl;
                cout << "  Current highest bid: " << priceTree->get(id) << endl;
                cout << "  Total bids placed: " << totalTree->get(id) << endl;
                cout << "  Successful bids: " << successTree->get(id) << endl;
                cout << "  Rejected bids: " << rejectTree->get(id) << endl;
            }
            else
                cout << "Item " << id << " not found." << endl;
        }
        else if (operation == "REPORT")
        {
            cout << "Auction Report:\nTotal items: " << priceTree->size() << "\nTotal bids placed: " << g_bids
                 << "\nTotal successful bids: " << g_succ << "\nTotal rejected bids: " << g_rej
                 << "\n\nItem Statistics:" << endl;
            priceTree->print('R');
        }
        // End your code here
        cout << "==============================\n";
    }

    in_file.close();
    // TODO: Delete...
    delete priceTree;
    delete totalTree;
    delete successTree;
    delete rejectTree;
    // End your code here
    return 0;
}