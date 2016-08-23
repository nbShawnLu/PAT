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

int main()
{
    int n;
    vector<int> dis;
    vector<int> absdis;
    int total = 0;
    cin >> n;
    dis.push_back(0);
    absdis.push_back(0);
    for (int i = 0;i != n;++i)
    {
        int t;
        cin >> t;
        dis.push_back(t);
        total += t;
        absdis.push_back(total);
    }
    int m;
    cin >> m;
    for (int i = 0;i != m;++i)
    {
        int start, end;
        int dis1, dis2;
        cin >> start >> end;
        dis1 = absdis[end - 1] - absdis[start - 1];
        if (dis1 < 0)dis1 = total + dis1;
        dis2 = total - dis1;
        cout << (dis1 < dis2 ? dis1 : dis2) << '\n';
    }
    return 0;
}


