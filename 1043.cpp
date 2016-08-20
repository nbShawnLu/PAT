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

bool isBST(vector<int> & subnums, vector<int> & post)
{
    vector<int>::iterator it = subnums.begin();
    int root = *(it++);
    vector<int> left;
    vector<int> right;
    for (;it != subnums.end() && (*it) < root;++it)
    {
        left.push_back(*it);
    }
    for (;it != subnums.end() && (*it) >= root;++it)
    {
        right.push_back(*it);
    }
    if (it != subnums.end())return false;
    bool rs = true;
    if (!left.empty())
        rs &= isBST(left, post);
    if (!right.empty())
        rs &= isBST(right, post);
    post.push_back(root);

    return rs;
}
bool ismBST(vector<int> & subnums, vector<int> & mpost)
{
    vector<int>::iterator it = subnums.begin();
    int root = *(it++);
    vector<int> left;
    vector<int> right;
    for (;it != subnums.end() && (*it) >= root;++it)
    {
        left.push_back(*it);
    }
    for (;it != subnums.end() && (*it) < root;++it)
    {
        right.push_back(*it);
    }
    if (it != subnums.end())return false;
    bool rs = true;
    if (!left.empty())
        rs &= ismBST(left, mpost);
    if (!right.empty())
        rs &= ismBST(right, mpost);
    mpost.push_back(root);

    return rs;
}
int main()
{
    int n;
    vector<int> nums;
    vector<int> post;
    vector<int> mpost;
    cin >> n;
    for (int i = 0;i != n;++i)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    bool rs, mrs;
    rs = isBST(nums, post);
    mrs = ismBST(nums, mpost);
    if (rs)
    {
        cout << "YES\n";
        for (int i = 0;i != post.size();++i)
        {
            if (i)cout << ' ';
            cout << post[i];
        }
    }
    else if (mrs)
    {
        cout << "YES\n";
        for (int i = 0;i != mpost.size();++i)
        {
            if (i)cout << ' ';
            cout << mpost[i];
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}


