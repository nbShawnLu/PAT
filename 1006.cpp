#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "algorithm"
#include "iomanip"

class item
{
public:
    std::string user;
    int in;
    int out;
};

int main()
{
    std::vector<item> items;
    int n;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        item temp;
        std::string sin,sout;
        std::cin >> temp.user;
        std::cin >> sin >> sout;

        std::string::iterator is;
        int itime;

        itime = 0;
        for (is = sin.begin(); is != sin.end(); ++is)
        {
            if (*is != ':')
            {
                itime *= 10;
                itime += (*is - '0');
            }
        }
        temp.in = itime;

        itime = 0;
        for (is = sout.begin(); is != sout.end(); ++is)
        {
            if (*is != ':')
            {
                itime *= 10;
                itime += (*is - '0');
            }
        }
        temp.out = itime;

        items.push_back(temp);
    }

    int min = -1, max = -1;
    std::string rsin, rsout;
    for (std::vector<item>::iterator it = items.begin(); it != items.end(); ++it)
    {
        if (min == -1 || (*it).in < min)
        {
            rsin = (*it).user;
            min = (*it).in;
        }
        if (max == -1 || (*it).out > max)
        {
            rsout = (*it).user;
            max = (*it).out;
        }
    }

    std::cout << rsin << ' ' << rsout;

    return 0;
}
