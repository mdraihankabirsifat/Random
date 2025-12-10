#include <bits/stdc++.h>
#define ll long long
#define tata "\n"
using namespace std;

class Teacher
{
private:
    double salary; // data hiding

public: // access modifier
    string name;
    string dept;
    // non parameterized constructor
    Teacher()
    {
        cout << "This is constructor." << tata; // no return type
        dept = "CSE";
    }
    // parameterized constructor
    Teacher(string n, string d, double sal)
    {
        cout << "This is parameterized constructor." << tata;
        name = n;
        dept = d;
        salary = sal;
    }
    // random function
    void changedept(string newdept)
    {
        dept = newdept;
    }
    // setter ==> to set private value
    void setsalary(double s)
    {
        salary = s;
    }
    // getter function
    double getsalary()
    {
        return salary;
    }
    void getinfo()
    {
        cout << "name: " << name << tata;
        cout << "dept: " << dept << tata;
        cout << "Salary: " << salary << tata;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Teacher t1;
    t1.name = "Sifat";
    t1.dept = "CSE";
    // t1.salary = 40000; becomes private not accessible from the main function
    t1.setsalary(40000);
    cout << t1.name << tata;
    cout << t1.dept << tata;
    cout << t1.getsalary() << tata;
    Teacher t2("Nayeem", "CSE", 39000.50);
    t2.getinfo();
    return 0;
}