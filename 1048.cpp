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

int main()
{
    int rs = 0;
    int n, total;
    int nn[501] = { 0 };
    cin >> n >> total;
    for (int i = 0;i != n;++i)
    {
        int t1, t2;
        cin >> t1;
        t2 = total - t1;
        if (t2 > 0 && t2 <= 500 && nn[t2] > 0)
        {
            if (rs == 0 || t1 < rs)
                rs = t1;
            if (rs == 0 || t2 < rs)
                rs = t2;
        }
        ++nn[t1];
    }
    if (rs != 0)
        cout << rs << ' ' << total - rs;
    else
        cout << "No Solution";
    return 0;
}


