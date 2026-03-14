#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Function to check the "health" of an I/O stream (Slide 22)
void showState(ios::iostate state)
{
    if (state & ios::goodbit)
        cout << "  [goodbit is set]" << endl; // No errors
    if (state & ios::eofbit)
        cout << "  [eofbit is set]" << endl; // End of file hit
    if (state & ios::failbit)
        cout << "  [failbit is set]" << endl; // Non-fatal error
    if (state & ios::badbit)
        cout << "  [badbit is set]" << endl; // Fatal error
}

int main()
{
    char *str = new char[80];
    ifstream in;
    ofstream out;

    try
    {
        // Opening files (Slide 21)
        in.open("test.cpp");
        out.open("test2.cpp");
        if (!in || !out)
            throw "File error";

        // tellg() and tellp() show the current pointer position
        cout << "getPointer: " << in.tellg() << " putPointer: " << out.tellp() << endl;

        // read() and write() handle blocks of data
        in.read(str, 80);
        out.write(str, 80);

        // seekg moves the 'get' pointer to a specific location (Slide 21)
        // ios::end moves relative to the end of the file
        in.seekg(0, ios::end);
        out.seekp(0, ios::end);

        cout << "End position: " << in.tellg() << endl;

        // Checking Stream States (Slide 22)
        ios::iostate state = in.rdstate();
        showState(state);

        // clear() resets the error flags so you can use the stream again
        in.clear();
    }
    catch (const char *e)
    {
        cout << e << endl;
    }

    return 0;
}