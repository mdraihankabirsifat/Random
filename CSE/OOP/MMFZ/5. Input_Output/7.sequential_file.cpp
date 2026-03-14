#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream in;
    ofstream out;
    // fstream can be used for both input and output
    // ios::out | ios::app opens for writing and appends to the end
    fstream out2("test3.cpp", ios::out | ios::app);
    char ch;

    try
    {
        in.open("test.cpp");
        if (!in)
            throw "Cannot open input file";

        out.open("test2.cpp", ios::out);
        if (!out)
            throw "Cannot open output file";
    }
    catch (const char *message)
    {
        cout << message << endl;
        return 1;
    }

    // Read first character
    in.get(ch);
    while (!in.eof())
    {
        out.put(ch);  // Write to first file
        out2.put(ch); // Write to second file (append mode)
        in.get(ch);   // Get next character
    }

    // Check if a file is still open before closing
    if (in.is_open())
        cout << "file already open\n";

    in.close();
    out.close();
    out2.close();

    return 0;
}