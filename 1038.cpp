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
class num
{
public:
    string n;
    bool operator<(num & that);
};

bool num::operator<(num & that)
{
    return this->n + that.n < that.n + this->n;
}
int main()
{
    int n;
    cin >> n;
    vector<num> nums;
    for (int i = 0;i != n;++i)
    {
        num tempnum;
        cin >> tempnum.n;
        nums.push_back(tempnum);
    }
    sort(nums.begin(), nums.end());
    int flag = 0;
    for (int i = 0;i != n;++i)
    {
        for (string::iterator it = nums[i].n.begin();it != nums[i].n.end();++it)
        {
            if (flag != 0)
            {
                cout << *it;
            }
            else
            {
                if (*it != '0')
                {
                    cout << *it;
                    flag = 1;
                }
            }
        }
    }
    if (flag == 0)
    {
        cout << '0';
    }
    return 0;
}
