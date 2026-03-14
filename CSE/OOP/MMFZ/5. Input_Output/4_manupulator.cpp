#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Output Manipulator: setup
 * This consolidates several formatting steps into one command.
 * It's perfect for preventing accidental errors in repetitive tasks.
 */
ostream &setup(ostream &os)
{
    os << hex << showbase << uppercase; // Base settings
    os.width(10);                       // Layout settings
    os.fill('*');                       // Padding settings
    return os;
}

/**
 * Input Manipulator: hex_input
 * Simplifies taking input for nonstandard devices or specific formats.
 */
istream &hex_input(istream &is)
{
    is >> hex;
    return is;
}

int main()
{
    int number;

    cout << "Enter a hexadecimal number: ";
    // Using our custom input manipulator
    cin >> hex_input >> number;

    // Using our custom output manipulator 'setup'
    // It applies hex, showbase, uppercase, width(10), and fill('*') all at once!
    cout << "You entered: " << setup << number << endl;

    return 0;
}