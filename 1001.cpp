#include "iostream"
#include "vector"
int main()
{
    int a, b;
    std::cin >> a >> b;
    int c;
    c = a + b;
    std::vector<int> rs;
    if (c < 0)
    {
        std::cout << '-';
        c = -c;
    }
    int n = 1;
    while (c / n)
    {
        n *= 1000;
    }
    n /= 1000;
    while (n > 0)
    {
        rs.push_back((c / n) % 1000);
        n /= 1000;
    }
    if (c == 0)std::cout << 0;
    for (std::vector<int>::iterator it = rs.begin(); it != rs.end(); ++it)
    {
        if (it != rs.begin())
        {
            if (*it < 100)std::cout << 0;
            if (*it < 10)std::cout << 0;
        }
        std::cout << *it;
        if (it != rs.end() - 1)std::cout << ',';
    }

    return 0;
}