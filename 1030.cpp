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

int dst[501][501] = { 0 };
int cost[501][501] = { 0 };
int itd[501][501] = { 0 };
int itc[501][501] = { 0 };
int nxt[501][501] = { 0 };

int main()
{
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    for (int i = 0;i != m;++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        dst[a][b] = c;
        cost[a][b] = d;
        nxt[a][b] = b;
        dst[b][a] = c;
        cost[b][a] = d;
        nxt[b][a] = a;
    }

    for (int i = 0;i != n;++i)
    {
        for (int j = 0;j != n;++j)
        {
            itd[i][j] = dst[i][j];
            itc[i][j] = cost[i][j];
        }
    }

    for (int k = 0;k != n;++k)
    {
        for (int i = 0;i != n;++i)
        {
            for (int j = 0;j != n;++j)
            {
                if (itd[i][k] && itd[k][j] && itd[i][j] > itd[i][k] + itd[k][j])
                {
                    itd[i][j] = itd[i][k] + itd[k][j];
                    itc[i][j] = itc[i][k] + itc[k][j];
                    nxt[i][j] = k;
                }
                else if (itd[i][k] && itd[k][j] && itd[i][j] == itd[i][k] + itd[k][j])
                {
                    if (itc[i][k] && itc[k][j] && itc[i][j] > itc[i][k] + itc[k][j])
                    {
                        itd[i][j] = itd[i][k] + itd[k][j];
                        itc[i][j] = itc[i][k] + itc[k][j];
                        nxt[i][j] = k;
                    }
                }
            }
        }
    }

    int ss = s;
    cout << s;
    while (s != e)
    {
        cout << ' ';
        s = nxt[s][e];
        cout << s;
    }

    cout <<' '<< itd[ss][e] << ' ' << itc[ss][e];

    return 0;
}

