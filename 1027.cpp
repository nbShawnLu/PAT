#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int str2int(string s, int r)
{
    int rs = 0;
    for (string::iterator it = s.begin();it != s.end();++it)
    {
        rs *= r;
        if (isalpha(*it))
        {
            rs += (*it) - 'A' + 10;
        }
        else
        {
            rs += (*it) - '0';
        }
    }
    return rs;
}

string int2rstr(int i, int r)
{
    if (i == 0)return "0";
    string rs;
    while (i > 0)
    {
        int temp = i%r;
        i /= r;
        if (temp > 9)
        {
            rs.push_back(temp - 10 + 'A');
        }
        else
        {
            rs.push_back(temp + '0');
        }
    }
    return rs;
}

int main()
{
    string c[3];
    cin >> c[0] >> c[1] >> c[2];
    cout << '#';
    for (int i = 0;i != 3;++i)
    {
        int temp = str2int(c[i], 10);
        string rs = int2rstr(temp, 13);
        if (rs.length() == 1)cout << '0';
        for (string::reverse_iterator it = rs.rbegin();it != rs.rend();++it)
        {
            cout << (*it);
        }
    }
    return 0;
}

