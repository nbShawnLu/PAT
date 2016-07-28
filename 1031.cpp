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


int main()
{
    string str;
    cin >> str;
    int n = str.size();

    int n1, n2;
    n1 = (n + 2) / 3;
    n2 = n + 2 - 2 * n1;

    int slow = 0;
    int fast = n - 1;
    for (int i = 0;i != n1;++i)
    {
        if (i == n1 - 1)
        {
            while (slow <= fast)
            {
                cout << str[slow++];
            }
        }
        else
        {
            cout << str[slow++];
            for (int j = 0;j != n2 - 2;++j)
            {
                cout << ' ';
            }
            cout << str[fast--];
            cout << '\n';
        }
    }

    return 0;
}

