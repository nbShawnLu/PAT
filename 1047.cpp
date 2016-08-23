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

int str2num(char * name)
{
    int rs = 0;
    rs = (int(name[0]) << 24) + (int(name[1]) << 16) + (int(name[2]) << 8) + int(name[3]);
    return rs;
}

int num2str(int n, char * name)
{
    name[4] = 0;
    name[3] = n & 0xff;
    name[2] = (n >> 8) & 0xff;
    name[1] = (n >> 16) & 0xff;
    name[0] = (n >> 24) & 0xff;
    return 0;
}

typedef vector<int> classes;

classes aclasses[2501];
int main()
{
    int ns, nc;
    cin >> ns >> nc;
    for (int i = 0;i != ns;++i)
    {
        char name[5];
        int iname;
        int nn, cc;
        scanf("%s %d", name, &nn);
        iname = str2num(name);
        for (int j = 0;j != nn;++j)
        {
            cin >> cc;
            aclasses[cc - 1].push_back(iname);
        }
    }
    for (int i = 0;i != nc;++i)
    {
        char name[5];
        int iname;
        cout << i+1 << ' ' << aclasses[i].size() << '\n';
        sort(aclasses[i].begin(), aclasses[i].end());
        for (int j = 0;j != aclasses[i].size();++j)
        {
            iname = aclasses[i][j];
            num2str(iname, name);
            printf("%s\n", name);
        }

    }
    return 0;
}


