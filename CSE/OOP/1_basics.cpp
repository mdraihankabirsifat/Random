#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define arr(v, x, y) vector<vector<ll>> v(x, vector<int>(y))
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define tata '\n'
using namespace std;

class Teacher
{
private:
    double salary;

public: // access modifier
    string name;
    string dept;
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
};

class Student
{
    string name;
    int id;
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
    cout << t1.getsalary() << tata;
    return 0;
}