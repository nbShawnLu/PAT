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
    std::vector<int> onums;
    std::vector<int> nums;
    nums.push_back(0);
    int n;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        int temp;
        std::cin >> temp;
        onums.push_back(temp);
        nums.push_back(temp);
    }

    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        if (it == nums.begin())continue;
        *it += *(it - 1);
    }
    int max=0;
    int flag = 0;
    std::vector<int>::iterator its, ite;
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        for (std::vector<int>::iterator it2 = it; it2 != nums.end(); ++it2)
        {
            if (it == it2)continue;
            int temp = *it2 - *it;
            if (flag == 0 || max < temp)
            {
                flag = 1;
                max = *it2 - *it;
                its = it + 1;
                ite = it2;
            }
        }
    }
    int rs1 = *its - *(its - 1);
    int rs2 = *ite - *(ite - 1);

    int alln = 1;
    for (std::vector<int>::iterator it = onums.begin(); it != onums.end(); ++it)
    {
        if (*it >= 0)alln = 0;
    }
    if (alln == 1)
    {
        max = 0;
        rs1 = *onums.begin();
        rs2 = *(onums.end() - 1);

    }
    std::cout << max << ' ' << rs1 << ' ' << rs2;

    return 0;
}
