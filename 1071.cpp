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
    map<string, int> patterns;
    
    string word;
    char ch;
    int imax = 0;
    string wmax;
    while (cin.get(ch))
    {
        if ((isdigit(ch) != 0) || (islower(ch) != 0))
        {
            word.push_back(ch);
        }
        else if (isupper(ch) !=0)
        {
            word.push_back(tolower(ch));
        }
        else
        {
            if (!word.empty())
            {
                ++patterns[word];
                int x = patterns[word];
                if (x > imax || (x == imax && word < wmax))
                {
                    imax = x;
                    wmax = word;
                }
            }
            word.clear();
            if (ch == '\n')
                break;
        }
    }
    cout << wmax << ' ' << imax;
    return 0;
}

