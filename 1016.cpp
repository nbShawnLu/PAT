#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "algorithm"
#include "iomanip"

using namespace std;


class ev
{
public:
    int month;
    int date;
    int hour;
    int min;
    string type;

    bool operator<(const ev & evr)const;
    void printev();
    int caltime(const ev & evr)const;
    float calfee(const ev & evr, const vector<int> &toll)const;
};

int ev::caltime(const ev & evr)const
{
    int rs = 0;
    rs += evr.date - this->date;
    rs *= 24;
    rs += evr.hour - this->hour;
    rs *= 60;
    rs += evr.min - this->min;
    if (rs < 0)rs = -rs;
    return rs;
}
float ev::calfee(const ev & evr, const vector<int> &toll)const
{
    int oneday = 0;
    for (vector<int>::const_iterator cit = toll.begin(); cit != toll.end(); ++cit)
    {
        oneday += *cit;
    }
    oneday *= 60;
    int rs = 0;
    float rsf;
    int dd = evr.date - this->date;
    rs += oneday * dd;
    int h1 = this->hour;
    int h2 = evr.hour;
    rs -= (this->min)*toll[h1];
    rs += (evr.min)*toll[h2];

    
    if (h1 > h2)
    {
        h2 += 24;
        rs -= oneday;
    }
    for (int i = h1; i != h2; ++i)
    {
        rs += toll[i % 24] * 60;
    }

    rsf = rs;
    rsf /= 100;
    return rsf;
}
void ev::printev()
{
    cout << setfill('0') << setw(2) << this->date << ':' << setfill('0') << setw(2) << this->hour
        << ':' << setfill('0') << setw(2) << this->min;
}

bool ev::operator<(const ev &evr)const
{
    //if (this->month < evr.month)return true;

    //if (this->month == evr.month)
    //{
    //    if (this->date < evr.date)return true;

    //    if (this->date == evr.date)
    //    {
    //        if (this->hour < evr.hour)return true;

    //        if (this->hour == evr.hour)
    //        {
    //            if (this->min < evr.min)return true;
    //        }
    //    }
    //}
    //return false;
    return (this->month * 1000000 + this->date * 10000 + this->hour * 100 + this->min
        < evr.month * 1000000 + evr.date * 10000 + evr.hour * 100 + evr.min);
}

bool cmpname(const pair<string, vector<ev>> itl, const pair<string, vector<ev>> itr)
{
    return (itl.first < itr.first);
}

int main()
{
    vector<int> toll;
    map<string, vector<ev>> persons;
    vector<pair<string, vector<ev>>> personnew;
    for (int i = 0; i != 24; ++i)
    {
        int temp;
        cin >> temp;
        toll.push_back(temp);
    }

    int n;
    cin >> n;
    for (int i = 0; i != n; ++i)
    {
        string tempn;
        ev tempev;
        char ex;
        cin >> tempn >> tempev.month >> ex >> tempev.date >> ex >> tempev.hour >> ex >> tempev.min >> tempev.type;
        map<string, vector<ev>>::iterator it = persons.find(tempn);
        if (it == persons.end())
        {
            vector<ev> tempevv;
            tempevv.push_back(tempev);
            persons.insert(make_pair(tempn, tempevv));
        }
        else
        {
            it->second.push_back(tempev);
        }
    }

    for (map<string, vector<ev>>::iterator it = persons.begin(); it != persons.end(); ++it)
    {
        sort(it->second.begin(), it->second.end());
        personnew.push_back(make_pair(it->first, it->second));
    }

    sort(personnew.begin(), personnew.end(), cmpname);

    for (vector<pair<string, vector<ev>>>::iterator it = personnew.begin(); it != personnew.end(); ++it)
    {
        float tt = 0;
        int flag = 0;
        
        for (vector<ev>::iterator itev = it->second.begin(); itev != it->second.end() - 1; ++itev)
        {
            if (itev->type == "on-line" && (itev + 1)->type == "off-line")
            {
                if (flag == 0)
                {
                    flag = 1;
                    cout << it->first << ' ';
                    cout << setfill('0') << setw(2) << it->second.begin()->month << '\n';
                }
                itev->printev();
                cout << ' ';
                (itev + 1)->printev();
                cout << ' ';
                int t = itev->caltime(*(itev + 1));
                cout << t << ' ';
                float f = itev->calfee(*(itev + 1),toll);
                cout << '$' << fixed << setprecision(2) << f << '\n';
                tt += f;
            }          
        }
        if (flag == 1)
        {
            cout << "Total amount: $" << fixed << setprecision(2) << tt << '\n';
        }
    }
    return 0;
}