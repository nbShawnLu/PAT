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
    int nc, np;
    vector<int> cn, cp, pn, pp;
    int rs = 0;
    
    cin >> nc;
    for (int i = 0;i != nc;++i)
    {
        int temp;
        cin >> temp;
        if (temp < 0)
        {
            cn.push_back(-temp);
        }
        if (temp > 0)
        {
            cp.push_back(temp);
        }
    }
    cin >> np;
    for (int i = 0;i != np;++i)
    {
        int temp;
        cin >> temp;
        if (temp < 0)
        {
            pn.push_back(-temp);
        }
        if (temp > 0)
        {
            pp.push_back(temp);
        }
    }
    sort(cn.rbegin(), cn.rend());
    sort(cp.rbegin(), cp.rend());
    sort(pn.rbegin(), pn.rend());
    sort(pp.rbegin(), pp.rend());
    int size;
    size = cn.size() < pn.size() ? cn.size() : pn.size();
    for (int i = 0;i != size;++i)
    {
        rs += cn[i] * pn[i];
    }
    size = cp.size() < pp.size() ? cp.size() : pp.size();
    for (int i = 0;i != size;++i)
    {
        rs += cp[i] * pp[i];
    }
    cout << rs;
    return 0;
}
