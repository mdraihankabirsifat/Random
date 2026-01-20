#include <iostream>
using namespace std;

int main()
{
    // 1. Save current flags so we can restore them later
    ios::fmtflags f = cout.flags();

    // Standard output
    cout << 123.45 << " " << -10 << " " << 100 << endl;

    // 2. Change to Hexadecimal and show the base (0x) and sign (+)
    cout.unsetf(ios::dec); // Must turn off decimal first
    cout.setf(ios::hex | ios::showbase | ios::showpos);
    cout << 123.45 << " " << -10 << " " << 100 << endl;
    // Output: +123.45 0xfffffff6 +0x64

    // 3. Scientific notation and uppercase
    ios::fmtflags f2 = ios::scientific | ios::showpoint | ios::uppercase;
    cout.setf(f2);
    cout << 123.45 << " " << 100.0 << endl;
    // Output: +1.234500E+02 +1.000000E+02

    // 4. Restore original flags
    cout.flags(f);
    cout << 123.45 << " " << -10 << endl; // Back to normal

    return 0;
}