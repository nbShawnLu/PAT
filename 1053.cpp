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
    int id;
    int val;
    vector<int> leafs;
};
vector<node> nodes;
int target;
int choose[100] = { 0 };
int index = 0;

void findpath(int root, int weight);

int main()
{
    int n, m;
    
    cin >> n >> m >> target;
    for (int i = 0;i != n;++i)
    {
        node tnode;
        tnode.id = i;
        cin >> tnode.val;
        nodes.push_back(tnode);
    }
    for (int i = 0;i != m;++i)
    {
        int id, nol;
        cin >> id >> nol;
        for (int j = 0;j != nol;++j)
        {
            int t;
            cin >> t;
            nodes[id].leafs.push_back(t);
        }
    }
    findpath(0, nodes[0].val);
    return 0;
}
bool cmp(int & l, int & r)
{
    return nodes[l].val < nodes[r].val;
}
void findpath(int index, int weight)
{
    if (weight == target && nodes[choose[index]].leafs.empty())
    {
        for (int i = 0;i <= index;++i)
        {
            if (i != 0)
                cout << ' ';
            cout << nodes[choose[i]].val;
        }
        cout << '\n';
    }
    else if (weight < target)
    {
        vector<int> next = nodes[choose[index]].leafs;
        sort(next.rbegin(), next.rend(),cmp);
        for (int i = 0;i != next.size();++i)
        {
            choose[index + 1] = next[i];
            findpath(index + 1, weight + nodes[next[i]].val);
        }
    }
    return;
}

