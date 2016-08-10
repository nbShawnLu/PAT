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
    int n;
    cin >> n;
    vector<int> nums;
    map<int, int> times;
    for (int i = 0;i != n;++i)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
        ++times[temp];
    }
    int i = 0;
    for (;i != n;++i)
    {
        if (times[nums[i]] == 1)
        {
            cout << nums[i];
            break;
        }
    }
    if (i == n)cout << "None";
    return 0;
}
