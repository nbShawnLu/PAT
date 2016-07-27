#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "algorithm"
#include "iomanip"
using namespace std;
#define MAX 1001
int snext[MAX][MAX];
int had[MAX];

int bl(int it,int ex,int n);

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            snext[i][j] = 0;
        }
    }

    for (int i = 0; i != m; ++i)
    {
        int a, b;
        cin >> a >> b;
        snext[a][b] = 1;
        snext[b][a] = 1;
    }
    for (int i = 0; i != k; ++i)
    {
        int t;
        cin >> t;
        int rs = 0;

        for (int j = 0; j < MAX; ++j)
        {
            had[j] = 0;
        }

        for (int j = 1; j <= n;++j)
        {
            if (j == t)continue;
            if (had[j]==0)
            {
                bl(j,t,n);
                ++rs;
            }
        }
        cout << rs - 1 << '\n';
    }
    return 0;
}

int bl(int it,int ex,int n)
{
    vector<int> t;
    vector<int> t2;
    t.push_back(it);
    while (!t.empty())
    {
        t2.clear();
        for (vector<int>::iterator it = t.begin(); it != t.end(); ++it)
        {
            if (had[*it]==0)
            {
                had[*it] = 1;
                for (int i = 1; i <= n;++i)
                {
                    if (i != ex && had[i] == 0 && snext[*it][i] == 1)
                    {
                        t2.push_back(i);
                    }
                }
            }
        }
        t.clear();
        for (vector<int>::iterator it = t2.begin(); it != t2.end(); ++it)
        {
            t.push_back(*it);
        }

    }
    return 0;
}