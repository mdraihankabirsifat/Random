#include <iostream>
#include <iomanip>
using namespace std;

ostream &setup(ostream &os)
{
    os << hex << showbase << uppercase; // set formatting
    //os << "str" << endl;
    os.width(10);
    os.fill('*');
    //os << "str" << endl;
    return os;
}

istream &hex_input(istream &is)
{
    is >> hex; // read input as hexadecimal
    return is;
}

int main()
{
    int number;
    cout << "Enter a hexadecimal number: ";
    cin >> hex_input >> number;                         // use custom input manipulator
    cout << "You entered: " << setup << number << endl; // custom output manipulator
    return 0;
}

/*
Key Notes:

1. Custom manipulators extend stream behavior.

2. Output manipulator returns ostream&.

3. Input manipulator returns istream&.

4. Useful for grouping multiple formatting operations.
*/