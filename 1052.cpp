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

class node
{
public:
    int addr;
    int val;
    int next;
    bool operator<(node &);
};

bool node::operator<(node & that)
{
    return this->val < that.val;
}

node all[100001];
int main()
{
    vector<node> inlist;
    int n, start;
    cin >> n >> start;
    for (int i = 0;i != n;++i)
    {
        node tnode;
        cin >> tnode.addr >> tnode.val >> tnode.next;
        all[tnode.addr] = tnode;
    }
    int next = start;
    while (next != -1)
    {
        inlist.push_back(all[next]);
        next = all[next].next;
    }
    sort(inlist.begin(), inlist.end());
    cout << inlist.size() << ' ';
    for (int i = 0;i != inlist.size();++i)
    {
        cout << setfill('0');
        cout << setw(5) << inlist[i].addr << '\n' << setw(5) << inlist[i].addr << ' ';
        cout<< inlist[i].val << ' ';
    }
    cout << -1;

    return 0;
}


