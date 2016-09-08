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
    int n;
    cin >> n;
    vector<int> nums;
    int t;
    int cuo = 0;
    int ncuo = 0;
    int nloop = 0;
    for (int i = 0;i != n;++i)
    {
        cin >> t;
        nums.push_back(t);
        if (i != t)
        {
            ++cuo;
        }        
    }
    ncuo = cuo;
    
    int flag = 0;
    if (nums[0] == 0)
        flag = 2;
    int it = 0;
    int slow = 0,fast = 0;
    while (cuo)
    {
        ++nloop;
        while (nums[it] == it)
            ++it;
        slow = it;
        fast = nums[slow];
        do
        {
            nums[slow] = slow;
            slow = fast;
            fast = nums[slow];
            --cuo;
        } while (slow != it);
    }
    cout << nloop + flag + ncuo - 2;
    return 0;
}

