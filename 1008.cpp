#include "iostream"

int main()
{
    int last = 0;
    int temp;
    int rs = 0;
    std::cin >> temp;
    while (std::cin >> temp)
    {
        if (temp > last)rs += (temp - last) * 6;
        if (temp < last)rs += (last - temp) * 4;
        rs += 5;
        last = temp;
    }
    std::cout << rs;
    return 0;
}