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
    std::string s;
    std::cin >> s;
    int rs = 0;
    std::string r;
    for (std::string::iterator is = s.begin(); is != s.end(); ++is)
    {
        int temp = *is - '0';
        rs += temp;
    }

    int n = 1;
    while (rs / n)
    {
        n *= 10;
    }
    n /= 10;

    int flag = 0;
    if (rs == 0)std::cout << "zero";
    while (n > 0)
    {
        int temp = (rs/n)%10;
        n /= 10;
        if (flag == 0)
        {
            flag = 1;
        }
        else
        {
            std::cout << ' ';
        }
        switch (temp)
        {
        case 0:
            std::cout << "zero";
            break;
        case 1:
            std::cout << "one";
            break;
        case 2:
            std::cout << "two";
            break;
        case 3:
            std::cout << "three";
            break;
        case 4:
            std::cout << "four";
            break;
        case 5:
            std::cout << "five";
            break;
        case 6:
            std::cout << "six";
            break;
        case 7:
            std::cout << "seven";
            break;
        case 8:
            std::cout << "eight";
            break;
        case 9:
            std::cout << "nine";
            break;
        default:;
        }

    }

    return 0;
}