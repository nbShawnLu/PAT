#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "algorithm"
#include "iomanip"

using namespace std;

class people
{
public:
    int time;
    int outtime;
};

bool allempty(vector<queue<people*>> & queues)
{
    for (vector<queue<people*>>::iterator it = queues.begin(); it != queues.end(); ++it)
    {
        if (!it->empty())
        {
            return false;
        }
    }
    return true;
}

vector<queue<people*>>::iterator smallest(vector<queue<people*>> & queues)
{
    vector<queue<people*>>::iterator rs = queues.begin();
    for (vector<queue<people*>>::iterator it = queues.begin(); it != queues.end(); ++it)
    {
        if (it->empty())continue;
        if (rs->empty() || (it->front())->time < (rs->front())->time)
        {
            rs = it;
        }
    }
    return rs;
}
int main()
{
    int n, m, q, k;
    cin >> n >> m >> q >> k;
    int now = 8 * 60;
    int close = 17 * 60;
    vector<queue<people*>> queues;
    vector<people> peoplen;
    vector<people> peopleo;

    vector<people>::iterator itp;
    for (int i = 0; i != n; ++i)
    {
        queue<people*> temp;
        queues.push_back(temp);
    }
    
    for (int i = 0; i != q; ++i)
    {
        people temp;
        cin >> temp.time;
        peoplen.push_back(temp);
        peopleo.push_back(temp);
    }
    itp = peoplen.begin();

    for (int i = 0; i != m; ++i)
    {
        for (int j = 0; j != n; ++j)
        {
            if (itp != peoplen.end())
            {
                queues[j].push(&*(itp++));
            }
        }
    }

    while ((!allempty(queues)))
    {
        vector<queue<people*>>::iterator sm = smallest(queues);
        int de = (sm->front())->time;
        now += de;
        for (int i = 0; i != n; ++i)
        {
            if (queues[i].empty())continue;
            queues[i].front()->time -= de;
            if (queues[i].front()->time == 0)
            {
                queues[i].front()->outtime = now;
                queues[i].pop();
                if (itp != peoplen.end())
                {
                    queues[i].push(&*(itp++));
                }
            }
        }
    }

    for (int i = 0; i != k; ++i)
    {
        int temp;
        int tt;
        cin >> temp;
        tt = peoplen[temp - 1].outtime;
        if ((tt - peopleo[temp - 1].time)< close)
        {
            cout << setfill('0') << setw(2) << tt / 60 << ':' << setfill('0') << setw(2) << tt % 60 << '\n';
        }
        else
        {
            cout << "Sorry\n";
        }
    }

    return 0;
}