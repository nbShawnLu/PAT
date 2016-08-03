#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

class student
{
public:
    string name;
    string gender;
    string ID;
    int grade;
    bool operator<(student & that);
};

bool student::operator<(student & that)
{
    return this->grade < that.grade;
}
int main()
{
    vector<student> males;
    vector<student> females;
    vector<student>::iterator itm;
    vector<student>::iterator itf;

    int n;
    cin >> n;
    for (int i = 0;i != n;++i)
    {
        student temp;
        cin >> temp.name >> temp.gender >> temp.ID >> temp.grade;
        if (temp.gender == "F")
        {
            females.push_back(temp);
        }
        else
        {
            males.push_back(temp);
        }
    }

    sort(females.begin(), females.end());
    sort(males.begin(), males.end());

    bool havef = false, havem = false;

    if (females.size() == 0)
    {
        cout << "Absent\n";
    }
    else
    {
        itf = females.end() - 1;
        havef = true;
        cout << itf->name << ' '<< itf->ID << '\n';
    }
    if (males.size() == 0)
    {
        cout << "Absent\n";
    }
    else
    {
        itm = males.begin();
        havem = true;
        cout << itm->name << ' '<< itm->ID << '\n';
    }

    if (havef && havem)
    {
        cout << itf->grade - itm->grade << '\n';
    }
    else
    {
        cout << "NA";
    }
    return 0;
}
