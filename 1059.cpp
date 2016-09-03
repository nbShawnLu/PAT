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

typedef vector<pair<long int, long int>> t_rs;
int main()
{
    ios::sync_with_stdio(false);
    t_rs rs;
    long int n;
    cin >> n;
    long int on = n;
    for (long int i = 2;i*i <= on;++i)
    {
        long int t = 0;
        while(n%i == 0)
        {
            ++t;
            n /= i;
        }
        if (t > 0)
            rs.push_back(make_pair(i, t));
        if (n == 1)
            break;
    }
    if (n > 1)
        rs.push_back(make_pair(n, 1));
    cout << on << '=';
    if (rs.empty())
        cout << 1;
    for (t_rs::iterator it = rs.begin();it != rs.end();++it)
    {
        if (it != rs.begin())
        {
            cout << '*';
        }
        cout << it->first;
        if (it->second > 1)
        {
            cout << '^' << it->second;
        }
    }
    return 0;
}

