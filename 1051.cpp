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
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0;i != k;++i)
    {
        bool rs = true;
        stack<int> st;
        int next = 1;
        char buf[10000];
        for (int j = 0;j != n;++j)
        {
            int t;
            cin >> t;
            if (t >= next)
            {
                while (t >= next)
                {
                    st.push(next++);
                }
                if (st.size() > m)
                {
                    rs = false;
                    gets(buf);
                    break;
                }
                st.pop();
            }
            else
            {
                if (st.empty() || t != st.top())
                {
                    rs = false;
                    gets(buf);
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if (rs)
            cout << "YES\n";
        else
            cout << "NO\n";
        
    }
    return 0;
}


