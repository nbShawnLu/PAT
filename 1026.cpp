#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

class member
{
public:
    int arrivetime;
    int playtime;

    int servicetime;
    int leavetime;

    bool vip;

    bool operator<(member & that);
};

bool member::operator<(member & that)
{
    return this->arrivetime < that.arrivetime;
}

bool paiser(const member &ml, const member &mr)
{
    return ml.servicetime < mr.servicetime;
}

bool isvip(set<int> & vips, int n)
{
    return (vips.find(n) != vips.end());
}

vector<queue<member>>::iterator findvip(vector<queue<member>> & queues, set<int> & vips, member tmb)
{
    vector<queue<member>>::iterator it = queues.begin();
    for (;it != queues.end();++it)
    {
        if (!isvip(vips, it - queues.begin()))continue;
        if (it->empty() || it->back().leavetime < tmb.arrivetime)
        {
            return it;
        }
    }
    return it;
}

vector<queue<member>>::iterator findord(vector<queue<member>> & queues, set<int> & vips, member tmb)
{
    vector<queue<member>>::iterator it = queues.begin();
    for (;it != queues.end();++it)
    {
        if (isvip(vips, it - queues.begin()))continue;
        if (it->empty() || it->back().leavetime < tmb.arrivetime)
        {
            return it;
        }
    }
    return it;
}

vector<queue<member>>::iterator findall(vector<queue<member>> & queues, set<int> & vips, member tmb)
{
    vector<queue<member>>::iterator it = queues.begin();
    for (;it != queues.end();++it)
    {
        if (it->empty() || it->back().leavetime < tmb.arrivetime)
        {
            return it;
        }
    }
    return it;
}

vector<queue<member>>::iterator findvipmin(vector<queue<member>> & queues, set<int> & vips, member tmb)
{
    int flag = 0;
    int min = 0;
    vector<queue<member>>::iterator rs = queues.end();
    for (vector<queue<member>>::iterator it = queues.begin();it != queues.end();++it)
    {
        if (!isvip(vips, it - queues.begin()))continue;
        if (flag == 0 || it->back().leavetime < min)
        {
            flag = 1;
            min = it->back().leavetime;
            rs = it;
        }
    }
    return rs;
}
vector<queue<member>>::iterator findordmin(vector<queue<member>> & queues, set<int> & vips, member tmb)
{
    int flag = 0;
    int min = 0;
    vector<queue<member>>::iterator rs = queues.end();
    for (vector<queue<member>>::iterator it = queues.begin();it != queues.end();++it)
    {
        if (isvip(vips, it - queues.begin()))continue;
        if (flag == 0 || it->back().leavetime < min)
        {
            flag = 1;
            min = it->back().leavetime;
            rs = it;
        }
    }
    return rs;
}
vector<queue<member>>::iterator findallmin(vector<queue<member>> & queues, set<int> & vips, member tmb)
{
    int flag = 0;
    int min = 0;
    vector<queue<member>>::iterator rs = queues.end();
    for (vector<queue<member>>::iterator it = queues.begin();it != queues.end();++it)
    {
        if (flag == 0 || it->back().leavetime < min)
        {
            flag = 1;
            min = it->back().leavetime;
            rs = it;
        }
    }
    return rs;
}

void insqueue(vector<queue<member>>::iterator itq, member & tmb)
{
    if (itq->empty() || itq->back().leavetime < tmb.arrivetime)
    {
        tmb.servicetime = tmb.arrivetime;
        tmb.leavetime = tmb.servicetime + tmb.playtime;
        itq->push(tmb);
    }
    else
    {
        tmb.servicetime = itq->back().leavetime;
        tmb.leavetime = tmb.servicetime + tmb.playtime;
        itq->push(tmb);
    }
}

int main()
{
    int n;
    char temp;
    vector<member> members;
    vector<queue<member>> queues;
    set<int> vips;
    cin >> n;
    cin.get(temp);

    for (int i = 0;i != n;++i)
    {
        member tmember;
        int h, m, s;
        int p, v;

        cin >> h >> temp >> m >> temp >> s >> p >> v;
        cin.get(temp);
        tmember.servicetime = 0;
        tmember.arrivetime = h * 3600 + m * 60 + s;
        tmember.playtime = p * 60;
        if (tmember.playtime > 120 * 60)tmember.playtime = 120 * 60;
        tmember.vip = (v == 1 ? true : false);

        members.push_back(tmember);
    }
    int na, nv;
    cin >> na >> nv;

    for (int i = 0;i != na;++i)
    {
        queue<member> tqueue;
        queues.push_back(tqueue);
    }

    for (int i = 0;i != nv;++i)
    {
        int a;
        cin >> a;
        vips.insert(a - 1);
    }


    sort(members.begin(), members.end());

    for (vector<member>::iterator it = members.begin();it != members.end();++it)
        if (it->arrivetime < 8 * 3600)it->arrivetime = 8 * 3600;
    for (vector<member>::iterator it = members.begin();it != members.end();++it)
    {
        if (it->servicetime != 0)continue;
        if (it->vip)
        {
            vector<queue<member>>::iterator itq;
            itq = findvip(queues, vips, *it);
            if (itq != queues.end())insqueue(itq, *it);
            else
            {
                itq = findall(queues, vips, *it);
                if (itq != queues.end())insqueue(itq, *it);
                else
                {
                    itq = findvipmin(queues, vips, *it);
                    vector<queue<member>>::iterator itq2 = findallmin(queues, vips, *it);
                    if (itq->back().leavetime > itq2->back().leavetime)itq = itq2;
                    insqueue(itq, *it);
                }
            }
        }
        else
        {
            vector<queue<member>>::iterator itq;
            itq = findall(queues, vips, *it);
            if (itq != queues.end())
            {
                if (isvip(vips, itq - queues.begin()))
                {
                    vector<member>::iterator itvv = it + 1;
                    for (;itvv != members.end();++itvv)
                    {
                        if (itvv->vip && itvv->servicetime == 0 && !itq->empty() && itvv->arrivetime < itq->back().leavetime)break;
                    }
                    if (itvv != members.end())
                    {
                        insqueue(itq, *itvv);
                        --it;
                    }
                    else
                    {
                        insqueue(itq, *it);
                    }
                }
                else
                {
                    insqueue(itq, *it);
                }
            }
            else
            {
                itq = findordmin(queues, vips, *it);
                vector<queue<member>>::iterator itq2 = findallmin(queues, vips, *it);
                if (itq->back().leavetime > itq2->back().leavetime)
                {
                    itq = itq2;
                    vector<member>::iterator itvv = it + 1;
                    for (;itvv != members.end();++itvv)
                    {
                        if (itvv->vip && itvv->servicetime == 0 && !itq->empty() && itvv->arrivetime < itq->back().leavetime)break;
                    }
                    if (itvv != members.end())
                    {
                        insqueue(itq, *itvv);
                        --it;
                    }
                    else
                    {
                        insqueue(itq, *it);
                    }
                }
                else
                {
                    insqueue(itq, *it);
                }     
            }
        }

    }
    stable_sort(members.begin(), members.end(), paiser);

    for (vector<member>::iterator it = members.begin();it != members.end();++it)
    {
        if (it->servicetime >= 21 * 3600)continue;
        int time = it->arrivetime;
        int h = time / 3600;
        int min = time % 3600 / 60;
        int sec = time % 60;
        cout << setfill('0');
        cout << setw(2) << h << ':' << setw(2) << min << ":" << setw(2) << sec << ' ';
        time = it->servicetime;
        h = time / 3600;
        min = time % 3600 / 60;
        sec = time % 60;
        cout << setw(2) << h << ':' << setw(2) << min << ":" << setw(2) << sec << ' ';
        cout << (it->servicetime - it->arrivetime + 30) / 60 << '\n';
    }

    for (vector<queue<member>>::iterator it = queues.begin();it != queues.end();++it)
    {
        int i = 0;
        while (!it->empty())
        {
            member tmember = it->front();
            if (tmember.servicetime >= 21 * 3600)
            {
                it->pop();
                continue;
            }
            ++i;
            it->pop();
        }
        if (it != queues.begin())cout << ' ';
        cout << i;
    }

    return 0;
}

