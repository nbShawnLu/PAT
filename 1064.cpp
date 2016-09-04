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

typedef pair<int, int> item;

int callevel(int n)
{
    int rs = 1;
    int mask = 1;
    while (n > mask)
    {
        ++rs;
        mask = (1 << rs) - 1;
    }
    return rs;
}

int calroot(int n, int level)
{
    int rs;
    int f = (1 << (level - 2)) - 1;
    int ff = n - 1 - 2 * f;
    if (ff > 1 << (level - 2))
        ff = 1 << (level - 2);
    rs = f + ff;
    return rs;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    vector<int> nums;
    queue<item> q;
    cin >> n;
    for (int i = 0;i != n;++i)
    {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    sort(nums.begin(), nums.end());
    q.push(make_pair(0, n));
    bool first = true;
    while (!q.empty())
    {
        if (first)
        {
            first = false;
        }
        else
        {
            cout << ' ';
        }
        item titem = q.front();
        q.pop();
        int offset = titem.first;
        int nn = titem.second;
        if (nn == 1)
        {
            cout << nums[offset];
        }
        else
        {
            int level = callevel(nn);
            int root = calroot(nn, level);
            cout << nums[offset + root];
            q.push(make_pair(offset, root));
            if (!(root == nn - 1))
            {
                q.push(make_pair(offset + root + 1, nn - root - 1));
            }
        }
        
        
    }
    return 0;
}

