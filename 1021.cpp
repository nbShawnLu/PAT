#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class node
{
public:
    int val;
    vector<int> next;
    int deep;
    int s;
};

int bl(vector<node> &nodes, int index);

int main()
{
    int n;
    cin >> n;
    vector<node> nodes;
    for (int i = 0;i != n;++i)
    {
        node tempn;
        tempn.val = i + 1;
        nodes.push_back(tempn);
    }
    for (int i = 1;i != n;++i)
    {
        int a, b;
        cin >> a >> b;
        nodes[a-1].next.push_back(b-1);
        nodes[b-1].next.push_back(a-1);
    }
    int flag = 0;
    for (int i = 0;i != n;++i)
    {
        int rs = bl(nodes, i);
        if (rs < n)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        int max = 0;
        for (int i = 0;i != n;++i)
        {
            if (nodes[i].deep>max)max = nodes[i].deep;
        }
        for (int i = 0;i != n;++i)
        {
            if (nodes[i].deep == max)cout << i + 1 << '\n';
        }
    }
    else
    {
        int rs = 0;
        vector<int> have;
        while(have.size()!=n)
        {
            ++rs;
            vector<int> v1;
            vector<int> v2;
            for (int i = 0;i != n;++i)
            {
                if (find(have.begin(), have.end(), i) == have.end())
                {
                    v1.push_back(i);
                    have.push_back(i);
                    break;
                }
            }
            while (!v1.empty())
            {
                v2.clear();
                for (vector<int>::iterator it = v1.begin();it != v1.end();++it)
                {
                    for (vector<int>::iterator it2 = nodes[*it].next.begin();it2 != nodes[*it].next.end();++it2)
                    {
                        if (find(have.begin(), have.end(), *it2) == have.end())
                        {
                            v2.push_back(*it2);
                            have.push_back(*it2);
                        }
                    }
                }
                v1 = v2;
            }
        } 
        cout << "Error: " << rs << " components";
    }

    return 0;
}

int bl(vector<node> &nodes, int index)
{
    int rs = 0;
    vector<int> have;
    for (int i = 0;i != nodes.size();++i)
    {
        have.push_back(0);
    }
    vector<int> v1;
    vector<int> v2;
    have[index]=1;
    v1.push_back(index);
    while (!v1.empty())
    {
        ++rs;
        v2.clear();
        for (vector<int>::iterator it = v1.begin();it != v1.end();++it)
        {
            for (vector<int>::iterator it2 = nodes[*it].next.begin();it2 != nodes[*it].next.end();++it2)
            {
                if (have[*it2]==0)
                {
                    v2.push_back(*it2);
                    have[*it2]=1;
                }
            }
        }
        v1 = v2;
    }
    int temps = 0;
    for (int i = 0;i != have.size();++i)
    {
        if (have[i] == 1)++temps;
    }
    nodes[index].s = temps;
    nodes[index].deep = rs;
    return temps;
}