#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "algorithm"
#include "iomanip"


int main()
{
    double a1, a2, a3;
    double rs = 0.65;
    char out[3];

    for (int i = 0; i != 3; ++i)
    {
        std::cin >> a1 >> a2 >> a3;
        out[i] = 'W';
        if (a2 > a1&& a2 > a3)
        {
            out[i] = 'T';
        }
        if (a3 > a2&&a3 > a1)
        {
            out[i] = 'L';
        }
        switch (out[i])
        {
        case 'W':
            rs *= a1;
            break;
        case 'T':
            rs *= a2;
            break;
        case 'L':
            rs *= a3;
            break;
        }
    }
    
    rs *= 2;
    rs -= 2;
    std::cout << out[0] << ' ' << out[1] << ' ' << out[2] << ' ' << std::fixed << std::setprecision(2) << rs;
    
    return 0;
}