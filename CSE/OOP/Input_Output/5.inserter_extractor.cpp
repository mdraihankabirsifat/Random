#include <iostream>
#include <cstring>
using namespace std;

class Inventory
{
    char itemName[20];
    int itemNumber;
    double price;

public:
    Inventory(char *name, int num, double cost)
    {
        strcpy(itemName, name);
        itemNumber = num;
        price = cost;
    }

    // Declaring friend functions so they can access private members
    friend ostream &operator<<(ostream &os, Inventory &inv);
    friend istream &operator>>(istream &is, Inventory &inv);
};

/**
 * Inserter Overloading (<<):
 * Allows: cout << item;
 * os: reference to ostream (like cout)
 * inv: reference to our object
 */
ostream &operator<<(ostream &os, Inventory &inv)
{
    os << "Item: " << inv.itemName << endl;
    os << "Item Number: " << inv.itemNumber << endl;
    os << "Price: " << inv.price << endl;
    return os; // Return stream to allow chaining: cout << a << b;
}

/**
 * Extractor Overloading (>>):
 * Allows: cin >> item;
 */
istream &operator>>(istream &is, Inventory &inv)
{
    cout << "Enter item name: ";
    is >> inv.itemName;
    cout << "Enter item number: ";
    is >> inv.itemNumber;
    cout << "Enter price: ";
    is >> inv.price;
    return is;
}

int main()
{
    Inventory item1("hammer", 1234, 19.95);

    // Using the overloaded <<
    cout << item1;

    // Using the overloaded >>
    cin >> item1;
    cout << item1;

    return 0;
}