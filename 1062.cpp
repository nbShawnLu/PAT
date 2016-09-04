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
    int id;
    int v;
    int t;
    int ttl;
    bool operator<(person & that);
};

bool person::operator<(person & that)
{
    if (ttl < that.ttl)
        return true;
    if (ttl == that.ttl)
    {
        if (v < that.v)
            return true;
        if (v == that.v)
        {
            return id > that.id;
        }
    }
    return false;
}

istream & operator>>(istream & input, person & p)
{
    input >> p.id >> p.v >> p.t;
    p.ttl = p.v + p.t;
    return input;
}
ostream & operator<<(ostream & output, person & p)
{
    output << p.id << ' ' << p.v << ' ' << p.t << '\n';
    return output;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, l, h;
    vector<person> persons[4];
    cin >> n >> l >> h;
    for (int i = 0;i != n;++i)
    {
        person t;
        cin >> t;
        if (t.v >= h)
        {
            if (t.t >= h)
            {
                persons[0].push_back(t);
            }
            else if (t.t >= l)
            {
                persons[1].push_back(t);
            }
        }
        else if (t.v >= l)
        {
            if (t.t > t.v)
            {
                persons[3].push_back(t);
            }
            else if (t.t >= l)
            {
                persons[2].push_back(t);
            }
        }
    }
    int num = 0;
    for (int i = 0;i != 4;++i)
    {
        sort(persons[i].rbegin(), persons[i].rend());
        num += persons[i].size();
    }
    cout << num << '\n';
    for (int i = 0;i != 4;++i)
    {
        for (int j = 0;j != persons[i].size();++j)
            cout << persons[i][j];
    }
    return 0;
}

