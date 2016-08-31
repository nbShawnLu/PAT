#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

class person
{
public:
    string name;
    int age;
    int worths;
};
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    vector<person> persons;
    cin >> n >> k;
    for (int i = 0;i != n;++i)
    {
        person temp;
        cin >> temp.name >> temp.age >> temp.worths;
        persons.push_back(temp);
    }
    sort(persons.begin(), persons.end(), [](const person & l, const person & r) 
    {
        if (l.worths > r.worths)
            return true;
        if (l.worths == r.worths)
        {
            if (l.age < r.age)
                return true;
            if (l.age == r.age)
            {
                if (l.name < r.name)
                    return true;
            }
        }
        return false;
    }
    );
    for (int i = 0;i != k;++i)
    {
        int nn, amin, amax;
        cin >> nn >> amin >> amax;
        vector<person> rs;
        for (int j = 0;j != persons.size();++j)
        {
            if (persons[j].age <= amax && persons[j].age >= amin)
            {
                rs.push_back(persons[j]);
                if (rs.size() == nn)
                    break;
            }
        }
        cout << "Case #" << i + 1 << ":\n";
        if (rs.size() > 0)
        {
            for (int j = 0;j != rs.size();++j)
            {
                cout << rs[j].name << ' ' << rs[j].age << ' ' << rs[j].worths << '\n';
            }
        }
        else
            cout << "None\n";
    }
    return 0;
}

