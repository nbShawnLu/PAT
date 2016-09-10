#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

bool sheng(char &l, char &r)
{
    return l < r;
}

bool jiang(char &l, char &r)
{
    return l > r;
}

int main()
{
    ios::sync_with_stdio(false);
    char cnum[6];
    int inum;
    cin >> inum;
    sprintf(cnum, "%04d", inum);
    
    do
    {
        int num1, num2;
        sort(cnum, cnum + 4, jiang);
        num1 = atoi(cnum);
        sort(cnum, cnum + 4, sheng);
        num2 = atoi(cnum);
        inum = num1 - num2;
        sprintf(cnum, "%04d", inum);
        cout << setfill('0');
        cout << setw(4) << num1 << " - " << setw(4) << num2 << " = " << setw(4) << inum << '\n';
    }while (inum != 0 && inum != 6174);
    return 0;
}

