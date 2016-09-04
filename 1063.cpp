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

typedef set<int> numset;
int main()
{
    ios::sync_with_stdio(false);
    vector<numset> sets;
    int n;

    cin >> n;
    for (int i = 0; i != n;++i)
    {
        int m;
        numset tnumset;
        cin >> m;
        for (int i = 0;i != m;++i)
        {
            int num;
            cin >> num;
            tnumset.insert(num);
        }
        sets.push_back(tnumset);
    }
    cin >> n;
    for (int i = 0;i != n;++i)
    {
        int a, b;
        int dup = 0, dis = 0;
        cin >> a >> b;
        numset & numseta = sets[a - 1];
        numset & numsetb = sets[b - 1];
        dis = numseta.size();
        for (numset::iterator it = numsetb.begin();it != numsetb.end();++it)
        {
            if (numseta.find(*it) != numseta.end())
            {
                ++dup;
            }
            else
            {
                ++dis;
            }
        }


        double rs = 100.0 * dup / dis;
        cout << fixed << setprecision(1) << rs << '%' << '\n';
    }
    return 0;
}

