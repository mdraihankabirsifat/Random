#include <iostream>
#include <fstream> // Required for file operations
using namespace std;

int main()
{
    // --- WRITING SECTION ---
    try
    {
        // ios::app means "append" - it adds to the end without deleting old data
        ofstream out("Inventory", ios::app);
        if (!out)
            throw "Cannot open output file";

        out << "Radios " << 39 << endl;
        out << "Toasters " << 21 << endl;
        out << "Mixers " << 17 << endl;

        out.close(); // Clean up
    }
    catch (const char *message)
    {
        cout << message << endl;
        return 1;
    }

    // --- READING SECTION ---
    try
    {
        ifstream in("Inventory");
        if (!in)
            throw "Cannot open input file";

        char item[20];
        int quantity;

        // while(!in.eof()) checks if we reached the end of the file
        in >> item >> quantity;
        while (!in.eof())
        {
            cout << item << ' ' << quantity << endl;
            in >> item >> quantity;
        }
        in.close();
    }
    catch (const char *message)
    {
        cout << message << endl;
    }

    return 0;
}