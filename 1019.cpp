#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool isr(vector<int>& vi)
{
    vector<int>::iterator it1 = vi.begin();
    vector<int>::iterator it2 = vi.end() - 1;
    while (it1 < it2)
    {
        if (*it1 != *it2)return false;
        ++it1;
        --it2;
    }
    return true;
}


vector<int> num2rstr(int n, int r)
{
    vector<int> rs;
    if (n == 0)rs.push_back(0);
    while (n)
    {
        rs.push_back(n%r);
        n /= r;
    }
    return rs;
}

int main()
{
 
    int n, r;
    cin >> n >> r;
    vector<int> str;
    str = num2rstr(n, r);
    if (isr(str))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    for (vector<int>::reverse_iterator rit = str.rbegin();rit != str.rend();++rit)
    {
        if (rit != str.rbegin())cout << ' ';
        cout << *rit;
    }
    return 0;
}

