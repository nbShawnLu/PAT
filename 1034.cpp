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

class head
{
public:
    string name;
    int size;
    bool operator< (head & that);
};

bool head::operator<(head & that)
{
    return this->name < that.name;
}

typedef map<string, int> gang;

void mergegang(gang & gang1, gang & gang2)
{
    for (gang::iterator it = gang2.begin();it != gang2.end();++it)
    {
        gang1.insert(make_pair(it->first,it->second));
    }
    gang2.clear();
}


int main()
{
    vector<gang> gangs;
    int n, ther;
    cin >> n >> ther;
    for (int i = 0;i != n;++i)
    {
        string name1, name2;
        int time;
        cin >> name1 >> name2;
        cin >> time;
        if (time > 1000 || time <= 0)
            continue;
        int j = 0;
        for (;j != gangs.size();++j)
        {
            if (gangs[j].find(name1) != gangs[j].end())
            {
                gangs[j][name1] += time;
                if (gangs[j].find(name2) != gangs[j].end())
                {
                    gangs[j][name2] += time;
                }
                else
                {
                    int k = 0;
                    for (;k != gangs.size();++k)
                    {
                        gang::iterator it = gangs[k].find(name2);
                        if (it != gangs[k].end())
                        {
                            mergegang(gangs[j], gangs[k]);
                            gangs[j][name2] += time;
                            break;
                        }
                    }
                    if (k == gangs.size())
                    {
                        gangs[j][name2] = time;
                    }
                }
                break;
            }
            else if (gangs[j].find(name2) != gangs[j].end())
            {
                int k = 0;
                for (;k != gangs.size();++k)
                {
                    gang::iterator it = gangs[k].find(name1);
                    if (it != gangs[k].end())
                    {
                        mergegang(gangs[j], gangs[k]);
                        gangs[j][name1] += time;
                        gangs[j][name2] += time;
                        break;
                    }
                }
                if (k == gangs.size())
                {
                    gangs[j][name1] = time;
                    gangs[j][name2] += time;
                }
                break;
            }
        }
        if (j == gangs.size())
        {
            gang tempgang;
            tempgang[name1] = time;
            tempgang[name2] = time;
            gangs.push_back(tempgang);
        }
    }
    vector<head> heads;
    for (int i = 0;i != gangs.size();++i)
    {
        int ttl = 0;
        gang::iterator itmax = gangs[i].begin();
        for (gang::iterator it = gangs[i].begin();it != gangs[i].end();++it)
        {
            ttl += it->second;
            if (it->second > itmax->second)
                itmax = it;
        }
        ttl /= 2;
        if (ttl > ther && gangs[i].size() > 2)
        {
            head temphead;
            temphead.name = itmax->first;
            temphead.size = gangs[i].size();
            heads.push_back(temphead);
        }
    }

    sort(heads.begin(), heads.end());
    cout << heads.size() << '\n';
    for (int i = 0;i != heads.size();++i)
    {
        cout << heads[i].name << ' ' << heads[i].size << '\n';
    }

    return 0;
}
