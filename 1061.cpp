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


int main()
{
    ios::sync_with_stdio(false);
    string line1, line2;
    char c1;
    int d, h, m;
    int flag = 0;
    string datemap[] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
    cin >> line1 >> line2;
    for (int i = 0;flag != 2;++i)
    {
        c1 = line1[i];
        switch (flag)
        {
            case 0:
                if (isupper(c1) && c1 <= 'G' && c1 == line2[i])
                {
                    flag = 1;
                    d = c1 - 'A';
                }
                break;
            case 1:
                if (isupper(c1) && c1 <= 'N' && c1 == line2[i])
                {
                    flag = 2;
                    h = c1 - 'A' + 10;
                }
                if (isdigit(c1) && c1 == line2[i])
                {
                    flag = 2;
                    h = c1 - '0';
                }
                break;
            default:
                break;
        }
    }
    cin >> line1 >> line2;
    for (int i = 0;flag != 3;++i)
    {
        c1 = line1[i];
        if (isalpha(c1) && c1 == line2[i])
        {
            flag = 3;
            m = i;
        }
    }
    cout << setfill('0');
    cout << datemap[d] << ' ' << setw(2) << h << ':' << setw(2) << m;
    return 0;
}

