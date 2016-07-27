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



int main()
{
    long n, m;
    vector<long> num1, num2;

    cin >> n;
    for (long i = 0;i != n;++i)
    {
        long t;
        cin >> t;
        num1.push_back(t);
    }

    cin >> m;
    for (long i = 0;i != m;++i)
    {
        long t;
        cin >> t;
        num2.push_back(t);
    }

    long o = (n + m + 1) / 2;

    vector<long>::iterator itslow = num1.begin();
    vector<long>::iterator itfast = num1.end();
    vector<long>::iterator itmid;
    vector<long>::iterator itmid2;
    if (m == 0)
    {
        cout << num1[o - 1];
        return 0;
    }
    if (n == 0)
    {
        cout << num2[o - 1];
        return 0;
    }
    if (n > m)
    {
        itfast = num1.begin() + o;
        itslow = num1.begin() + o - m;
    }

    long rs;
    while (itslow <= itfast)
    {
        
        itmid = (itfast - itslow) / 2 + itslow;
        itmid2 = num2.begin() + (o - (itmid - num1.begin()));


        if (itmid > num1.begin() && itmid2 < num2.end() && *(itmid - 1) > *itmid2)
        {
            itfast = itmid - 1;
            continue;
        }
        else if (itmid < num1.end() && itmid2 > num2.begin() && *(itmid) < *(itmid2 - 1))
        {
            itslow = itmid + 1;
            continue;
        }
        else
        {
            long a = 0, b = 0;
            if (itmid != num1.begin())a = *(itmid - 1);
            if (itmid2 != num2.begin())b = *(itmid2 - 1);
            rs = a > b ? a : b;
            break;
        }
    }

    cout << rs;
    return 0;
}

