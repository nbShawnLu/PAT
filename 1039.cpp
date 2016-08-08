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

typedef vector<int> mapstudents;

int str2int(char * str)
{
    int rs;
    rs = (str[0] - 'A') * 6760 + (str[1] - 'A') * 260 + (str[2] - 'A') * 10 + (str[3] - '0');
    return rs;
}

mapstudents students[175761];//26*26*26*10+1;
int have[175761] = { 0 };

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0;i != m;++i)
    {
        int id,num;
        scanf("%d %d", &id, &num);
        for (int j = 0;j != num;++j)
        {
            char cstuid[5];
            scanf("%s", cstuid);
            students[str2int(cstuid)].push_back(id);
        }
    }
    for (int i = 0;i != n;++i)
    {
        char cstuid[5];
        scanf("%s",cstuid);
        sort(students[str2int(cstuid)].begin(), students[str2int(cstuid)].end());
        if (i != 0)cout << '\n';
        printf("%s ", cstuid);
        printf("%d",students[str2int(cstuid)].size());
        for (int j = 0;j != students[str2int(cstuid)].size();++j)
        {
            printf(" %d",students[str2int(cstuid)][j]);
        }

    }
    return 0;
}
