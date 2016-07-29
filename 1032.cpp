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
    int head1, head2;
    int n;
    cin >> head1 >> head2 >> n;

    unordered_map<int, int> nodes;
    unordered_map<int, unordered_map<int, int>::const_iterator> nodesadd;
    unordered_set<int> ss;

    int i;
    int rs = -1;
    for (i = 0;i != n;++i)
    {
        int add, next;
        char ch;
        scanf("%d %c %d", &add, &ch, &next);
        nodes.insert(make_pair(add, next));
    }
    nodes.insert(make_pair(-1, -1));
    unordered_map<int, int>::const_iterator it;

    for (it = nodes.begin();it != nodes.end();++it)
    {
        nodesadd[it->first] = it;
    }
    it = nodesadd[head1];
    while (it->first != -1)
    {
        ss.insert(it->first);
        it = nodesadd[it->second];
    }

    it = nodesadd[head2];
    while (it->first != -1)
    {
        if (ss.find(it->first) != ss.end())
        {
            rs = it->first;
            break;
        }
        it = nodesadd[it->second];
    }
    if (rs == -1)
        cout << -1;
    else
        printf("%05d",rs);
    return 0;
}
