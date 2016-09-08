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
vector<int> nums;
vector<int> rem;
int slc[10001] = { 0 };
int index = 0;
int solution = 0;
int n, target;
int step = 0;//for test
int cal(int index, int weight)
{
    //++step;
    if (solution)
        return 0;
    if (weight == target)
    {
        solution = 1;
        int flag = 0;
        for (int i = 0;i != index;++i)
        {
            if (slc[i] == 1)
            {
                if (flag == 0)
                {
                    flag = 1;
                }
                else
                {
                    cout << ' ';
                }
                cout << nums[i];
            }
        }
        return 0;
    }
    if (weight > target)
    {
        return 3;
    }
    else
    {
        if (index == n)
        {
            return 2;
        }
        if (weight + rem[index] < target)
        {
            return 4;
        }
        else
        {
            slc[index] = 1;
            int rs = cal(index + 1, weight + nums[index]);
            slc[index] = 0;
            if (rs != 3 && !solution)
                cal(index + 1, weight);
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> target;
    for (int i = 0;i != n;++i)
    {
        int t;
        cin >> t;
        nums.push_back(t);
        rem.push_back(0);
    }
    for (int i = n - 1;i >= 0;--i)
    {
        if (i == n - 1)
        {
            rem[i] = nums[i];
        }
        else
        {
            rem[i] = rem[i + 1] + nums[i];
        }
    }
    sort(nums.begin(), nums.end());
    cal(0, 0);
    if (!solution)
        cout << "No Solution";
    //cout << step;
    return 0;
}

