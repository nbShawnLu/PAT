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
    const int n = 54;
    int next[n];
    int place[n];
    string name[n];
    int t;
    cin >> t;
    for (int i = 0;i != n;++i)
    {
        cin >> next[i];
        next[i] -= 1;
        place[i] = i;
    }
    for (int i = 0;i != t;++i)
    {
        for (int j = 0;j != n;++j)
        {
            place[j] = next[place[j]];
        }
    }
    for (int i = 0;i != n;++i)
    {
        
        int kind, num;
        string ckind;
        kind = i / 13;
        num = i % 13 + 1;
        switch (kind)
        {
        case 0 :
            ckind = 'S';
            break;
        case 1:
            ckind = 'H';
            break;
        case 2:
            ckind = 'C';
            break;
        case 3:
            ckind = 'D';
            break;
        case 4:
            ckind = 'J';
            break;
        default :
            break;
        }
        name[place[i]] = ckind + to_string(num);
    }
    for (int i = 0;i != n;++i)
    {
        if (i != 0)cout << ' ';
        cout << name[i];
    }
    return 0;
}
