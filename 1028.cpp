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

class student
{
public:
    string id;
    string name;
    int score;
};

bool pai1(const student & sl, const student & sr)
{
    return sl.id < sr.id;
}

bool pai2(const student & sl, const student & sr)
{
    return sl.name < sr.name;
}

bool pai3(const student & sl, const student & sr)
{
    return sl.score < sr.score;
}

int main()
{
    int n, f;
    cin >> n >> f;
    vector<student> students;
    for (int i = 0;i != n;++i)
    {
        student temp;
        char a[7];
        char b[9];
        int c;
        scanf("%s %s %d", a, b, &c);
        temp.id = string(a);
        temp.name = string(b);
        temp.score = c;
        students.push_back(temp);
    }
    sort(students.begin(), students.end(), pai1);
    switch (f)
    {
    case 1:
        break;
    case 2:
        stable_sort(students.begin(), students.end(), pai2);
        break;
    case 3:
        stable_sort(students.begin(), students.end(), pai3);
        break;
    default:
        ;
    }
    for (vector<student>::iterator it = students.begin();it != students.end();++it)
    {
        cout << it->id << ' ' << it->name << ' ' << it->score << '\n';
    }

    return 0;
}

