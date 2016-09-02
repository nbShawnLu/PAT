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
#include <string.h>

using namespace std;

int num[100001] = { 0 };
int pos, posn;
int main()
{
    //ios::sync_with_stdio(false);
    int n;
    stack<int> st;
    cin >> n;
    pos = 0;
    posn = 0;
    char cmd[10];
    while (n--)
    {
        int key;
        scanf("%s",cmd);
        if (strcmp(cmd, "Push") == 0)
        {
            scanf("%d", &key);
            st.push(key);
            ++num[key];
            if (key <= pos)
                ++posn;
            if (st.size() == 1)
            {
                pos = key;
                posn = 1;
            }
        }
        if (strcmp(cmd, "Pop") == 0)
        {
            if (st.size() == 0)
            {
                cout << "Invalid\n";
            }
            else
            {
                key = st.top();
                st.pop();
                --num[key];
                if (key <= pos)
                    --posn;
                cout << key << '\n';
                if (st.empty())
                {
                    pos = 0;
                    posn = 0;
                }
            }
        }
        if (strcmp(cmd, "PeekMedian") == 0)
        {
            if (st.empty())
            {
                cout << "Invalid\n";
            }
            else
            {
                int s = st.size();
                s = (s + 1) / 2;
                if (posn == s)
                {
                    while (num[pos] == 0)--pos;
                    cout << pos << '\n';
                }
                else if (posn < s)
                {
                    for (;;)
                    {
                        ++pos;
                        if (num[pos]>0)
                            posn += num[pos];
                        if (posn >= s)
                        {
                            cout << pos << '\n';
                            break;
                        }
                    }
                }
                else if(posn > s)
                {
                    for (;;)
                    {
                        if (num[pos]>0)
                            posn -= num[pos];
                        --pos;
                        if (posn == s)
                        {
                            while (num[pos] == 0)--pos;
                            cout << pos << '\n';
                            break;
                        }
                        if (posn < s)
                        {
                            ++pos;
                            if(num[pos]>0)
                                posn += num[pos];
                            while (num[pos] == 0)++pos;
                            cout << pos << '\n';
                            break;
                        }
                    }
                }
            } 
        }
    }
    return 0;
}

