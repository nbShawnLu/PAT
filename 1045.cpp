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

int rs[10001][201];
int main()
{
    int n, m, l;
    int ms[201];
    int ls[10001];
    cin >> n;

    cin >> m;
    for (int i = 0;i != m;++i)
    {
        int t;
        cin >> t;
        ms[i] = t;
    }
    cin >> l;
    for (int i = 0;i != l;++i)
    {
        int t;
        cin >> t;
        ls[i] = t;
    }
    int temp = ls[l - 1] == ms[m - 1] ? 1 : 0;
    rs[l - 1][m - 1] = temp;
    for (int i = m - 2;i >= 0;--i)
    {
        temp += ls[l - 1] == ms[i] ? 1 : 0;
        rs[l - 1][i] = temp;
    }
    temp = ls[l - 1] == ms[m - 1] ? 1 : 0;
    for (int i = l - 2;i >= 0;--i)
    {
        temp += ls[i] == ms[m - 1] ? 1 : 0;
        rs[i][m - 1] = temp;
    }
    for (int i = l - 2;i >= 0;--i)
    {
        for (int j = m - 2;j >= 0;--j)
        {
            int t = rs[i + 1][j] > rs[i][j + 1] ? rs[i + 1][j] : rs[i][j + 1];
            rs[i][j] = t + (ls[i] == ms[j] ? 1 : 0);
        }
    }
    cout << rs[0][0];
    return 0;
}


