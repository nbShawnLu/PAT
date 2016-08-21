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
    int n, target;
    vector<int> nums;
    map<int, int> answer;
    int slow = 0, fast = 0;
    
    cin >> n >> target;
    for (int i = 0;i != n;++i)
    {
        int t;
        cin >> t;
        nums.push_back(t);
    }

    slow = 0, fast = 0;
    int rsslow, rsfast;
    int delta = -1;
    int sum = nums[0];
    while (fast != n)
    {
        if (sum < target)
        {
            ++fast;
            if (fast == n)break;
            sum += nums[fast];
        }
        else if (sum >= target)
        {
            if (delta == -1 || sum - target < delta)
            {
                delta = sum - target;
                answer.clear();
                answer.insert(make_pair(slow, fast));
            }
            else if (sum - target == delta)
            {
                answer.insert(make_pair(slow, fast));
            }
            sum -= nums[slow];
            ++slow;
        }
    }
    for (map<int, int>::iterator it = answer.begin();it != answer.end();++it)
    {
        cout << it->first + 1 << '-' << it->second + 1 << '\n';
    }

    return 0;
}


