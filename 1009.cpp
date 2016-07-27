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
    int n;
    std::map<int, float> num1, num2, pdc;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        int a;
        float b;
        std::cin >> a >> b;
        num1[a] = b;
    }
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        int a;
        float b;
        std::cin >> a >> b;
        num2[a] = b;
    }

    for (std::map<int, float>::iterator it = num1.begin(); it != num1.end(); ++it)
    {
        for (std::map<int, float>::iterator it2 = num2.begin(); it2 != num2.end(); ++it2)
        {
            int a = it->first + it2->first;
            float b = it->second * it2->second;
            std::map<int, float>::iterator it3 = pdc.find(a);
            if (it3 == pdc.end())
            {
                pdc[a] = b;
            }
            else
            {
                pdc[a] += b;
            }
        }
    }

    int max = 0,nn=0;
    std::map<int, float> rs;

    for (std::map<int, float>::iterator it = pdc.begin(); it != pdc.end(); ++it)
    {
        if (it->second > 0.0001 || it->second<-0.0001)
        {
            ++nn;
            rs.insert(std::make_pair(it->first,it->second));
            if (it->first > max)max = it->first;

        }
    }

    std::cout << nn;
    while (max >= 0)
    {
        
        std::map<int, float>::iterator it = rs.find(max);
        if (it != rs.end())
        {
            std::cout << ' ';
            std::cout << it->first;
            std::cout << ' ';
            std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) << it->second;
        }
        --max;
    }

    return 0;
}