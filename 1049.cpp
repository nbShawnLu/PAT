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
    cin >> n;
    int rs = 0;
    int it = 1;
    for (;it <= n;it *= 10)
    {
        int a, b, c;
        a = n - it + 1;
        
        b = a / (10 * it);
        b *= it;

        c = a % (10 * it);
        c = c < it ? c : it;
        
        rs += (b + c);
    }
    cout << rs;
    return 0;
}


