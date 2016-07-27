#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class stu
{
public:
    string id;
    int score;
    int grank;
    int local;
    int lrank;
    bool operator<(const stu & stur)const;
};

bool stu::operator<(const stu & stur)const
{
    return this->score > stur.score;
}

bool pname(const stu & stul, const stu & stur)
{
    return stul.id < stur.id;
}

int lpai(vector<stu> & stus)
{
    int n = stus.size();
    for (int i = 0;i != n;++i)
    {
        if (i > 0)
        {
            if (stus[i].score == stus[i - 1].score)stus[i].lrank = stus[i - 1].lrank;
            else stus[i].lrank = i + 1;
        }
        else
        {
            stus[i].lrank = i + 1;
        }
    }
    return 0;
}

int gpai(vector<stu> & stus)
{
    int n = stus.size();
    for (int i = 0;i != n;++i)
    {
        if (i > 0)
        {
            if (stus[i].score == stus[i - 1].score)stus[i].grank = stus[i - 1].grank;
            else stus[i].grank = i + 1;
        }
        else
        {
            stus[i].grank = i + 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    vector<stu> glbstu;
    for (int i = 0;i != n;++i)
    {
        int n2;
        cin >> n2;

        vector<stu> lclstu;
        for (int j = 0;j != n2;++j)
        {
            stu temp;
            cin >> temp.id >> temp.score;
            temp.local = i + 1;
            lclstu.push_back(temp);
        }
        sort(lclstu.begin(), lclstu.end());
        lpai(lclstu);

        for (int i = 0;i != lclstu.size();++i)
        {
            glbstu.push_back(lclstu[i]);
        }
    }

    sort(glbstu.begin(), glbstu.end(),pname);
    stable_sort(glbstu.begin(), glbstu.end());
    gpai(glbstu);

    cout << glbstu.size() << '\n';
    for (int i = 0;i != glbstu.size();++i)
    {
        cout << glbstu[i].id << ' ' << glbstu[i].grank << ' ' << glbstu[i].local << ' ' << glbstu[i].lrank << '\n';
    }

    return 0;
}

