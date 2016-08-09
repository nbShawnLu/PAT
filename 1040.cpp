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
    char cstr[1001];
    string str;
    cin.getline(cstr,1001);
    str = cstr;
    int max = 0;
    for (string::iterator it = str.begin();it != str.end();++it)
    {
        int rs = 0;
        string::iterator itslow = it;
        string::iterator itfast = it;
        while (*itslow == *itfast)
        {
            ++rs;
            if (itslow == str.begin())
                break;
            else
                --itslow;
            if (itfast == str.end() - 1)
                break;
            else
                ++itfast;
        }
        if (2 * rs - 1 > max)max = 2 * rs - 1;

        rs = 0;
        itslow = it;
        itfast = it + 1;
        if (itfast == str.end())break;
        while (*itslow == *itfast)
        {
            ++rs;
            if (itslow == str.begin())
                break;
            else
                --itslow;
            if (itfast == str.end() - 1)
                break;
            else
                ++itfast;
        }
        if (2 * rs > max)max = 2 * rs;
    }
    if (str.size() > 0)
        cout << max;
    else
        cout << 0;
    return 0;
}
