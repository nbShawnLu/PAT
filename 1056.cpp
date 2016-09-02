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

class person
{
public:
    int pos;
    int order;
    int weights;
    int rank;
};

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    vector<person> persons;
    vector<int> rem;
    cin >> n >> m;
    for (int i = 0;i != n;++i)
    {
        person t;
        cin >> t.weights;
        t.pos = i;
        t.rank = n;
        persons.push_back(t);
    }
    for (int i = 0;i != n;++i)
    {
        int t;
        cin >> t;
        persons[t].order = i;
        rem.push_back(t);
    }
    /*sort(persons.begin(), persons.end(), [](const person & l, const person & r)
    {
        return l.order < r.order;
    });*/
    while (rem.size()>1)
    {
        vector<int> lastrem(rem);
        rem.clear();
        for (int i = 0;i < lastrem.size();i += m)
        {
            int nn = lastrem[i];
            int max = persons[nn].weights;
            for (int ii = i + 1;ii != i + m && ii != lastrem.size();++ii)
            {
                if (persons[lastrem[ii]].weights > max)
                {
                    nn = lastrem[ii];
                    max = persons[nn].weights;                 
                }
            }
            rem.push_back(nn);
            persons[nn].rank = 0;
        }
        for (int i = 0;i < lastrem.size();++i)
        {
            int nn = lastrem[i];
            if (persons[nn].rank != 0)
                persons[nn].rank = rem.size() + 1;
            else
                persons[nn].rank = rem.size();
        }
    }
    /*sort(persons.begin(), persons.end(), [](const person & l, const person & r)
    {
        return l.weights < r.weights;
    });*/
    for (int i = 0;i != n;++i)
    {
        if (i != 0)
        {
            cout << ' ';
        }
        cout << persons[i].rank;
    }
    return 0;
}

