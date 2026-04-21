#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class st_record
{
    string name;
    double cgpa;

public:
    st_record(string s = "", double cg = 0.0)
    {
        name = s;
        cgpa = cg;
    }
    double getCG() { return cgpa; }
    string getName() { return name; }
};
int main()
{
    map<int, st_record> result;
    result[3] = st_record("A", 3.2);
    result[1] = st_record("B", 3.6);
    result[20] = st_record("C", 3.4);
    result[32] = st_record("D", 2.0);
    int key = 3;
    for (auto i : result)
    {
        if (i.second.getCG() > result[key].getCG())
            key = i.first;
    }
    cout << "Highest CG:" << endl;
    cout << "Student number: " << key << endl;
    cout << "Name: " << result[key].getName() << endl;
    cout << "CGPA: " << result[key].getCG() << endl;
}