#include <iostream>
#include <fstream>
using namespace std;

void showState(ios::iostate state)
{

    if (state & ios::goodbit)
        cout << "goodbit is set" << endl;
    if (state & ios::eofbit)
        cout << "eofbit is set" << endl;
    if (state & ios::failbit)
        cout << "failbit is set" << endl;
    if (state & ios::badbit)
        cout << "badbit is set" << endl;
}

int main()
{

    char *str = new char[80];

    ifstream in;
    ofstream out;

    try
    {

        in.open("test.cpp");

        if (!in)
            throw "Cannot open input file";

        out.open("test2.cpp");

        if (!out)
            throw "Cannot open output file";
    }

    catch (const char *message)
    {

        cout << message << endl;
        return 1;
    }

    cout << "getPointer: " << in.tellg()
         << " putPointer: " << out.tellp() << endl;

    in.read(str, 80);   // read 80 bytes
    out.write(str, 80); // write 80 bytes

    cout << "getPointer: " << in.tellg()
         << " putPointer: " << out.tellp() << endl;

    in.seekg(0, ios::end);  // move get pointer
    out.seekp(0, ios::end); // move put pointer

    cout << "getPointer: " << in.tellg()
         << " putPointer: " << out.tellp() << endl;

    ios::iostate state = in.rdstate(); // check stream state
    showState(state);

    in.clear(); // clear error flags

    return 0;
}

/*
Key Notes:

1. tellg() → current input pointer position.

2. tellp() → current output pointer position.

3. seekg() / seekp() → move file pointers.

4. read() / write() used for binary file operations.

5. rdstate() checks stream error flags.
*/