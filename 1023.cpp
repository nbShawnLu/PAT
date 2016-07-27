#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int rs[10] = {};
    
    string n, m;

    cin >> n;
    int jin = 0;
    for (string::reverse_iterator it = n.rbegin();it != n.rend();++it)
    {
        int vn = *it - '0';
        ++rs[vn];
        int temp = vn * 2 + jin;
        jin = temp / 10;
        m.push_back(temp % 10 + '0');
    }
    if (jin != 0)m.push_back(jin + '0');

    for (string::reverse_iterator it = m.rbegin();it != m.rend();++it)
    {
        --rs[*it - '0'];
    }

    for (int i = 0;i != 10;++i)
    {
        if (rs[i] != 0)
        {
            cout << "No\n";
            for (string::reverse_iterator it = m.rbegin();it != m.rend();++it)
            {
                cout << *it;
            }
            return 0;
        }
    }
    cout << "Yes\n";
    for (string::reverse_iterator it = m.rbegin();it != m.rend();++it)
    {
        cout << *it;
    }
    return 0;
}

