#include "iostream"
#include "vector"
#include "map"
#include <iomanip> 
int main()
{
    int n;
    int max=0;
    std::map<int, float> ifm;
    std::cin >> n;
    while (n--)
    {
        int a1;
        float a2;
        std::cin >> a1;
        std::cin >> a2;
        ifm[a1] = a2;
        if (a1 > max)max = a1;
    }
    std::cin >> n;
    while (n--)
    {
        int a1;
        float a2;
        std::cin >> a1;
        std::cin >> a2;
        std::map<int, float>::iterator itm = ifm.find(a1);
        if (itm == ifm.end())ifm[a1] = a2;
        else ifm[a1] += a2;

        if (a1 > max)max = a1;
    }
    int s = 0;
    for (std::map<int, float>::iterator itm = ifm.begin(); itm != ifm.end();++itm)
    {
        if (itm->second - 0 > 0.0001 || itm->second - 0 < -0.0001)++s;
    }
     
    std::cout << s;
    if (s > 0)std::cout << ' ';
    while (max >= 0)
    {
        
        std::map<int, float>::iterator itm = ifm.find(max);
        if (itm != ifm.end())
        {
            if (ifm[max] - 0>0.0001 || ifm[max] - 0<-0.0001)
            {
                --s;
                std::cout << max << ' ' << std::setiosflags(std::ios::fixed) << std::setprecision(1) << ifm[max];
                if (s > 0)std::cout << ' ';
            }
        }
        --max;
    }

    return 0;
}