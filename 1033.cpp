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

class station
{
public:
    float price;
    int dis;
    int index;
};

vector<int> addto;

bool paiprice(station & sl, station & sr)
{
    return sl.price < sr.price;
}

bool paidis(station & sl, station & sr)
{
    return sl.dis < sr.dis;
}

vector<station>::iterator findcheapest(vector<station> & stations)
{
    vector<station>::iterator rs = stations.begin();
    for (vector<station>::iterator it = stations.begin();it != stations.end();++it)
    {
        if (it->price < rs->price)
        {
            rs = it;
        }
    }
    return rs;
}

vector<station>::iterator findnext(vector<station> & stations)
{
    vector<station>::iterator rs = stations.begin();
    for (vector<station>::iterator it = stations.begin();it != stations.end();++it)
    {
        if (it->dis < rs->dis)
        {
            rs = it;
        }
    }
    return rs;
}

bool fun(vector<station> & stations, int capdis, int dis, int start)
{
    /*
    for (int i = 0;i != stations.size();++i)cout << stations[i].dis << ' ' << stations[i].price << '\n';
    cout << dis << ' '<< start << '\n';
    cout << '\n';
    */

    vector<station>  stations1;
    vector<station>  stations2;
    int dis1, dis2;
    bool rs1, rs2;
    vector<station>::iterator itcheap = findcheapest(stations);
    int discheap = itcheap->dis;

    //no need to fill
    if (start > dis)return true;

    //devide into two parts
    dis1 = itcheap->dis;

    for (vector<station>::iterator it = stations.begin();it != stations.end();++it)
    {
        if (it->dis < itcheap->dis)
        {
            stations1.push_back(*it);
        }
        else if (it->dis > itcheap->dis)
        {
            station temp;
            temp.dis = it->dis;
            temp.price = it->price;
            temp.index = it->index;
            stations2.push_back(temp);
        }
    }
    if (stations1.empty())
    {
        //no need to deal with the left part
        rs1 = true;
    }
    else
    {
        //from 0 to cheapest
        rs1 = fun(stations1, capdis, dis1, start);
        if (rs1 == false)
        {
            return false;
        }
    }

    if (capdis >= (dis - itcheap->dis))
    {
        //no need to full
        addto[itcheap->index] = (dis - itcheap->dis);
        return true;
    }
    else
    {
        addto[itcheap->index] = capdis;
        if (stations2.empty())
        {
            //impossible       
            return false;
        }
        else
        {
            vector<station>::iterator itnext = findnext(stations2);
            int s2 = itnext->dis;
            for (int i = 0;i != stations2.size();++i)
            {
                stations2[i].dis -= s2;
            }
            int start2 = capdis - s2 + itcheap->dis;
            dis2 = dis - s2;
            rs2 = fun(stations2, capdis, dis2, start2);
            if (rs2 == false)
                return false;
        }
    }
    return true;
}
int main()
{
    int cap, dis, per, n;
    vector<station> stations;
    cin >> cap >> dis >> per >> n;
    for (int i = 0;i != n;++i)
    {
        station temp;
        cin >> temp.price >> temp.dis;
        stations.push_back(temp);
    }

    sort(stations.begin(), stations.end(), paidis);

    if (stations[0].dis > 0)
    {
        cout << "The maximum travel distance = ";
        printf("%.2f", 0.0);
        return 0;
    }

    for (int i = 0;i != stations.size();++i)
    {
        stations[i].index = i;
        addto.push_back(0);
    }
    float rsprice = 0;
    int rsdis = 0;
    bool rs;
    int start = 0;
    int capdis = cap*per;

    rs = fun(stations, capdis, dis, start);

    int tt = 0;
    int lasti = 0;

    rs = false;
    for (int i = 0;i != stations.size();++i)
    {
        if (i == 0)
        {
            tt = addto[0];
            rsprice = tt * stations[0].price;
            rsdis = tt;
        }
        else if (addto[i] > 0)
        {
            int dd = stations[i].dis - stations[lasti].dis;
            if (dd > capdis)
            {
                rsdis = stations[lasti].dis + capdis;
                rs = false;
                break;
            }
            tt -= dd;
            rsprice += (addto[i] - tt)*stations[i].price;
            tt = addto[i];
            lasti = i;
            rsdis = addto[i] + stations[i].dis;
        }
        if (rsdis >= dis)
        {
            rs = true;
            break;
        }

    }

    rsprice /= per;
    if (rs)
    {
        printf("%.2f", rsprice);
    }
    else
    {
        cout << "The maximum travel distance = ";
        printf("%.2f", float(rsdis));
    }

    return 0;
}
