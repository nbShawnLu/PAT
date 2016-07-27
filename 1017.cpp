#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class customer
{
public:
    int intime;
    int stime;
    int outtime;
    int time;
    bool operator<(const customer & cr);
};

bool customer::operator<(const customer & cr)
{
    return (this->intime<cr.intime);
}
bool allempty(vector<queue<customer>> & wins)
{
    for (vector<queue<customer>>::iterator it = wins.begin();it != wins.end();++it)
    {
        if (!it->empty())return false;
    }
    return true;
}

vector<queue<customer>>::iterator minwin(vector<queue<customer>> & wins)
{
    int flag = 0;
    vector<queue<customer>>::iterator min = wins.end();
    for (vector<queue<customer>>::iterator it = wins.begin();it != wins.end();++it)
    {
        if (it->empty())continue;
        if (flag == 0 || it->front().outtime < min->front().outtime)
        {
            flag = 1;
            min = it;
        }
    }
    return min;
}

vector<queue<customer>>::iterator findempty(vector<queue<customer>> & wins)
{
    vector<queue<customer>>::iterator it = wins.begin();
    for (;it != wins.end();++it)
    {
        if (it->empty())return it;
    }
    return it;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<customer> customers;
    vector<queue<customer>> wins;
    for (int i = 0;i != n;++i)
    {
        char tempc;
        customer tempcus;
        int temph,tempm, temps;
        cin >> temph >> tempc >> tempm >> tempc >> temps >> tempcus.time;
        tempcus.intime = 3600 * temph + 60 * tempm + temps;
        tempcus.time *= 60;
        customers.push_back(tempcus);
    }

    sort(customers.begin(), customers.end());

    for (int i = 0;i != k;++i)
    {
        queue<customer> tempq;
        customer tempcus;
        tempcus.intime = 8 * 3600;
        tempcus.stime = 8 * 3600;
        tempcus.outtime = 8 * 3600;
        tempcus.time = 0;
        tempq.push(tempcus);
        wins.push_back(tempq);
    }

    vector<customer>::iterator itv = customers.begin();
    int now = 8 * 3600;
    int tt = 0;
    int num = 0;
    while (itv != customers.end() && itv->intime <= 17 * 3600)
    {
        vector<queue<customer>>::iterator itn = findempty(wins);
        if (itn != wins.end())
        {
            itv->stime = itv->intime;
            itv->outtime = itv->stime + itv->time;
            itn->push(*itv);
        }
        else
        {
            itn = minwin(wins);
            if (itn != wins.end())
            {
                if(itn->front().outtime > itv->intime)
                {
                    tt += itn->front().outtime - itv->intime;
                    itv->stime = itn->front().outtime;
                }
                else
                {
                    itv->stime = itv->intime;
                }
                itv->outtime = itv->stime + itv->time;
                itn->push(*itv);
                itn->pop();
            }
        }
        ++itv;
        ++num;
    }

    cout << fixed << setprecision(1) << float(tt) / 60 / num;
    return 0;
}