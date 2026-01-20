#include <iostream>
#include <cstring>
using namespace std;

// --- Version 1: Without Virtual (Static Binding) ---
class Father
{
    char name[20];

public:
    Father(char *fname) { strcpy(name, fname); }
    // Non-virtual function: the compiler looks at the pointer type, not the object
    void show()
    {
        cout << "Father: " << name << endl;
    }
};

class Son : public Father
{
    char name[20];

public:
    Son(char *sname, char *fname) : Father(fname)
    {
        strcpy(name, sname);
    }
    // Overriding the base class method
    void show()
    {
        cout << "Son: " << name << endl;
    }
};

// --- Version 2: With Virtual (Dynamic Binding) ---
class FatherVirtual
{
    char name[20];

public:
    FatherVirtual(char *fname) { strcpy(name, fname); }
    // virtual keyword: tells the compiler to check the object type at runtime
    virtual void show()
    {
        cout << "Father: " << name << endl;
    }
};

class SonVirtual : public FatherVirtual
{
    char name[20];

public:
    SonVirtual(char *sname, char *fname) : FatherVirtual(fname)
    {
        strcpy(name, sname);
    }
    void show()
    {
        cout << "Son: " << name << endl;
    }
};

int main()
{
    // Scenario 1: WITHOUT VIRTUAL
    cout << "--- Without Virtual ---" << endl;
    Father fatherObj("Rashid");
    Son sonObj("Robin", "Rashid");
    Father *fp;

    fp = &fatherObj;
    fp->show(); // Output: Father: Rashid

    fp = &sonObj;
    fp->show(); // Output: Father: Rashid (Still calls Base because fp is a Father*)

    // Scenario 2: WITH VIRTUAL
    cout << "\n--- With Virtual ---" << endl;
    FatherVirtual fvObj("Rashid");
    SonVirtual svObj("Robin", "Rashid");
    FatherVirtual *fvp;

    fvp = &fvObj;
    fvp->show(); // Output: Father: Rashid

    fvp = &svObj;
    fvp->show(); // Output: Son: Robin (Calls Derived because of 'virtual')

    return 0;
}