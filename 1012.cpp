#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "algorithm"
#include "iomanip"

class student
{
public:
    std::string ID;
    int score[4];
    int rank[4];
};
int main()
{
    int n, m;
    std::vector<student> students;
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
    {
        student temp;
        std::cin >> temp.ID >> temp.score[0] >> temp.score[1] >> temp.score[2];
        temp.score[3] = (temp.score[0] + temp.score[1] + temp.score[2]) / 3;
        students.push_back(temp);
    }

    for (int i = 0; i != 4; ++i)
    {
        int s[101];
        for (int j = 0; j != 101; ++j)
        {
            s[j] = 0;
        }
        for (std::vector<student>::iterator it = students.begin(); it != students.end(); ++it)
        {
            ++s[it->score[i]];
        }
        for (int j = 100; j != 0; --j)
        {
            s[j-1] += s[j];
        }
        for (std::vector<student>::iterator it = students.begin(); it != students.end(); ++it)
        {
            if (it->score[i] == 100)
            {
                it->rank[i] = 1;
            }
            else
            {
                it->rank[i] = s[it->score[i]+1] + 1;
            }
        }

    }

    for (int i = 0; i != m; ++i)
    {
        std::string tempid;
        std::cin >> tempid;
        std::vector<student>::iterator it = students.begin();

        for (; it != students.end();++it)
        {
            if (it->ID == tempid)
            {
                char rs = 'A';
                int rsr = it->rank[3];
                if (it->rank[0] < rsr)
                {
                    rs = 'C';
                    rsr = it->rank[0];
                }
                if (it->rank[1] < rsr)
                {
                    rs = 'M';
                    rsr = it->rank[1];
                }
                if (it->rank[2] < rsr)
                {
                    rs = 'E';
                    rsr = it->rank[2];
                }
                std::cout << rsr << ' ' << rs;
                break;
            }
        }
        if (it == students.end())
        {
            std::cout << "N/A";
        }
        std::cout << '\n';
    }
    return 0;
}