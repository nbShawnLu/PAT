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
    char a[10005];
    char b[10005];
    char have[256] = { 0 };
    gets(a);
    gets(b);

    char *pa, *pb;
    pa = a;
    pb = b;
    while (*pb != 0 && *pb != '\n')
    {
        have[*pb] = 1;
        ++pb;
    }
    while (*pa != 0 && * pb != '\n')
    {
        if (!have[*pa])
            printf("%c", *pa);
        ++pa;
    }
    return 0;
}


