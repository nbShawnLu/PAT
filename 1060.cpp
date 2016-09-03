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


int main()
{
    ios::sync_with_stdio(false);
    int n;
    string n1, n2;
    int dot1, dot2;
    int dig1, dig2;
    int wei1, wei2;
    vector<char> rs1, rs2;
    bool isequal = true;
    cin >> n >> n1 >> n2;
    dot1 = n1.find('.');
    dot2 = n2.find('.');
    if (dot1 == string::npos)
        dot1 = n1.length();
    else
        n1.erase(dot1, 1);
    if (dot2 == string::npos)
        dot2 = n2.length();
    else
        n2.erase(dot2, 1);
    wei1 = dot1;
    wei2 = dot2;
    if (n1[0] == '0')
    {
        dig1 = n1.find_first_not_of('0');
        if (dig1 == string::npos)
            wei1 = 0;
        else
        {
            n1.erase(0, dig1);
            wei1 = dot1 - dig1;
        }
    }
    if (n2[0] == '0')
    {
        dig2 = n2.find_first_not_of('0');
        if (dig2 == string::npos)
            wei2 = 0;
        else
        {
            n2.erase(0, dig2);
            wei2 = dot2 - dig2;
        }
    }


    if (wei1 != wei2)
        isequal = false;

    for (int i = 0;i != n;++i)
    {
        if (i < n1.size())
        {
            rs1.push_back(n1[i]);
        }
        else
        {
            rs1.push_back('0');
        }

        if (i < n2.size())
        {
            rs2.push_back(n2[i]);
        }
        else
        {
            rs2.push_back('0');
        }
    }
    if (rs1 != rs2)
        isequal = false;
    if (isequal)
    {
        cout << "YES ";
        cout << "0.";
        for (int i = 0;i != rs1.size();++i)
        {
            cout << rs1[i];
        }
        cout << "*10^" << wei1;
    }
    else
    {
        cout << "NO ";
        cout << "0.";
        for (int i = 0;i != rs1.size();++i)
        {
            cout << rs1[i];
        }
        cout << "*10^" << wei1;
        cout << " 0.";
        for (int i = 0;i != rs2.size();++i)
        {
            cout << rs2[i];
        }
        cout << "*10^" << wei2;
    }
    return 0;
}

