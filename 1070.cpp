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

class mooncake
{
public:
    double inventory;
    double price;
    double pprice;
};

int main()
{
    ios::sync_with_stdio(false);
    int type, n;
    double rs = 0;
    vector<mooncake> cakes;
    mooncake tcake;
    cin >> type >> n;
    for (int i = 0;i != type; ++i)
    {
        cin >> tcake.inventory;
        cakes.push_back(tcake);
    }
    for (int i = 0;i != type;++i)
    {
        cin >> cakes[i].price;
        cakes[i].pprice = cakes[i].price / cakes[i].inventory;
    }
    sort(cakes.begin(), cakes.end(), [](const mooncake & l, const mooncake &r)
    {
        return l.pprice > r.pprice;
    });
    int i = 0;
    while (n >= 0 && i!=cakes.size())
    {
        if (cakes[i].inventory > n)
        {
            rs += cakes[i].pprice * n;
            n = 0;
        }
        else
        {
            rs += cakes[i].price;
            n -= cakes[i].inventory;
        }
        ++i;
    }
    cout << fixed << setprecision(2) << rs;
    return 0;
}

