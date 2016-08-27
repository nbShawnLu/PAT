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
const int n = 1 << 24;
int num[n] = { 0 };

int main()
{
    int row, col;
    cin >> row >> col;
    int all = row * col;
    for (int i = 0;i != all;++i)
    {
        int t;
        scanf("%d", &t);
        ++num[t];
        if (num[t] * 2 > all)
        {
            cout << t;
            break;
        }
    }
    return 0;
}

