#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>

using namespace std;

bool ispa(string & str)
{
    string::iterator it1 = str.begin();
    string::iterator it2 = str.end() - 1;
    while (it1 < it2)
    {
        if (*it1 != *it2)return false;
        ++it1;
        --it2;
    }
    return true;
}

string rvs(string & str)
{
    string rs;
    for (string::reverse_iterator it = str.rbegin();it != str.rend();++it)
    {
        rs.push_back(*it);
    }
    return rs;
}

string stradd(string & s1, string & s2)
{
    string rs;
    string::reverse_iterator it1 = s1.rbegin();
    string::reverse_iterator it2 = s2.rbegin();
    int jin = 0;
    while (it1 != s1.rend() && it2 != s2.rend())
    {
        int i1 = 0, i2 = 0;
        int he;
        if (it1 != s1.rend())
        {
            i1 = *it1 - '0';
            ++it1;
        }
        if (it2 != s2.rend())
        {
            i2 = *it2 - '0';
            ++it2;
        }
        he = i1 + i2 + jin;
        jin = he / 10;
        rs.push_back(he % 10 + '0');
    }
    if (jin > 0)rs.push_back(jin + '0');
    return rvs(rs);
}

int main()
{
    string input;
    int n;
    cin >> input >> n;

    if (ispa(input))
    {
        cout << input << '\n' << 0;
        return 0;
    }

    int i = 0;
    for (;i != n;++i)
    {
        string r = rvs(input);
        string sum = stradd(input, r);
        input = sum;
        if (ispa(sum))
        {
            break;
        }
    }
    if (i < n)++i;
    cout << input<<'\n' << i;
    return 0;
}

