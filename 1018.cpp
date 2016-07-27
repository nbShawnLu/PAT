#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class station
{
public:
    int n;
    map<int,int> next;
};
class path
{
public:
    vector<int> p;
    int l;
    int take;
    int back;
    int num;
    bool operator<(const path & pr);
};

bool path::operator<(const path & pr)
{
    return (this->l < pr.l);
}

void bl(vector<station> &stations, int des, int now, vector<int> p);

vector<path> paths;

int main()
{
    int c, n, m, r;
    cin >> c >> n >> m >> r;
    int g = c / 2;

    vector<station> stations;
    station o;
    stations.push_back(o);

    for (int i = 0;i != n;++i)
    {
        int t;
        station st;
        cin >> t;
        st.n = t;
        stations.push_back(st);
    }

    for (int i = 0;i != r;++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        stations[a].next[b] = c;
        stations[b].next[a] = c;
    }
    vector<int> p0;

    bl(stations, m, 0, p0);

    for (vector<path>::iterator it = paths.begin();it != paths.end();++it)
    {
        int tl = 0, tn = 0,ts=0;
        int min = 0;
        for (vector<int>::iterator it2 = (it->p).begin() + 1;it2 != (it->p).end();++it2)
        {
            ++tn;
            ts += stations[*it2].n;
            ts -= g;
            if (ts < min)min=ts;
            tl += stations[*it2].next[*(it2 - 1)];
        }
        it->l = tl;
        it->num = tn;
        it->take = -min;
        it->back = it->take + ts;
    }

    sort(paths.begin(), paths.end());

    int minl = paths.begin()->l;
    int minn = 0;
    int flag = 0;
    vector<path>::iterator rsit = paths.begin();
    for (vector<path>::iterator it = paths.begin();it != paths.end() && it->l == minl;++it)
    {
        int temp = it->take;
        if (flag == 0 || minn > temp)
        {
            flag=1;
            minn = temp;
            rsit = it;
        }
    }

    int minb = 0;
    flag = 0;
    vector<path>::iterator rsit2 = paths.begin();
    for (vector<path>::iterator it = paths.begin();it != paths.end() && it->l == minl;++it)
    {
        if (it->take > minn)continue;
        int temp = it->back;
        if (flag == 0 || minb > temp)
        {
            flag = 1;
            minb = temp;
            rsit2 = it;
        }
    }

    cout << rsit2->take;
    cout << ' ';
    for (vector<int>::iterator it = rsit2->p.begin();it != rsit2->p.end();++it)
    {
        cout << *it;
        if (it != rsit2->p.end()-1)cout << "->";
    }
    cout << ' ';
    cout << rsit2->back;

    return 0;
}

void bl(vector<station> &stations, int des, int now, vector<int> p)
{
    if (find(p.begin(), p.end(), now) != p.end())return;

    p.push_back(now);
    if (now == des)
    {
        path temp;
        temp.p = p;
        paths.push_back(temp);
        return;
    }
    for (map<int, int>::iterator it = stations[now].next.begin();it != stations[now].next.end();++it)
    {
        if (find(p.begin(), p.end(), it->first) != p.end())continue;
        else
        {
            bl(stations, des, it->first, p);
        }
    }
    return;

}