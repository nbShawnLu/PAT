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

class num
{
public:
    string n;
    int sgn;
    num operator+(num & r);
    bool operator>(num & r);
};

num num::operator+(num & r)
{
    num rs;
    string rrs;
    string::reverse_iterator it1 = n.rbegin();
    string::reverse_iterator it2 = r.n.rbegin();
    int jin = 0;
    while (it1 != n.rend() || it2 != r.n.rend())
    {
        int temp = 0;
        if (it1 != n.rend())
        {
            temp += (*it1 - '0')*sgn;
            ++it1;
        }
        if (it2 != r.n.rend())
        {
            temp += (*it2 - '0')*r.sgn;
            ++it2;
        }
        temp += jin;
        jin = temp / 10;
        if (temp < 0)
            jin = -1;
        if (temp < 0)
            temp += 10;
        rrs.push_back(temp % 10 + '0');
    }
    if (jin > 0)
        rrs.push_back('1');

    if (jin < 0)
        rs.sgn = -1;
    else
        rs.sgn = 1;
    if (rs.sgn>0)
    {
        for (string::reverse_iterator it = rrs.rbegin();it != rrs.rend();++it)
        {
            rs.n.push_back(*it);
        }
    }
    
    int i = rs.n.find_first_not_of('0');
    rs.n.erase(0, i);
    if (rs.n.empty())
        rs.sgn = 0;
    return rs;
}

bool num::operator>(num & r)
{
    if (sgn > r.sgn)
    {
        return true;
    }
    else if (sgn == r.sgn)
    {
        if (sgn == 1)
        {
            if (n.size() > r.n.size())
                return true;
            else if (n.size() == r.n.size())
                return n > r.n;
        }
        else
        {
            if (n.size() > r.n.size())
                return false;
            else if (n.size() == r.n.size())
                return n < r.n;
        }
    }
    return false;
}

istream & operator>>(istream & input, num & n)
{
    input >> n.n;
    if (n.n[0] == '-')
    {
        n.n.erase(0, 1);
        n.sgn = -1;
    }
    else
    {
        n.sgn = 1;
    }
    return input;
}

int main()
{
    ios::sync_with_stdio(false);
    num a, b, c, d;
    int n;
    cin >> n;
    for (int i = 0;i != n;++i)
    {
        cin >> a >> b >> c;
        if (a.sgn == b.sgn)
        {
            int sgn = a.sgn;
            a.sgn = 1;
            b.sgn = 1;
            d = a + b;
            d.sgn = sgn;
        }
        else
        {
            int sgn = a.sgn;
            a.sgn = 1;
            b.sgn = 1;
            if (a > b)
            {
                b.sgn = -1;
                d = a + b;
                d.sgn = sgn;
            }
            else
            {
                a.sgn = -1;
                d = a + b;
                d.sgn = -sgn;
            }

        }
        bool rs = d > c;
        cout << "Case #" << i + 1 << ": " << ((rs == true) ? "true\n" : "false\n");
    }


    return 0;
}

