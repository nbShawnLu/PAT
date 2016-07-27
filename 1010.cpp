#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "algorithm"
#include "iomanip"

#define OVER 1000000000000

long long str2num(std::string & st, long long r,long long th)
{
    long long rs = 0;

    for (std::string::iterator it = st.begin(); it != st.end(); ++it)
    {
        int inum;
        rs *= r;
        if ((*it) <= '9' && (*it) >= '0')
        {
            inum = (*it) - '0';
        }
        else
        {
            inum = (*it) - 'a' + 10;
        }
        rs += inum;
        if (rs > th&&th >= 0)return -1;
    }

    return rs;
}

int maxr(std::string & st)
{
    int max = 0;
    for (std::string::iterator it = st.begin(); it != st.end(); ++it)
    {
        int inum;
        if ((*it) <= '9' && (*it) >= '0')
        {
            inum = (*it) - '0';
        }
        else
        {
            inum = (*it) - 'a' + 10;
        }
        if (inum > max)max = inum;
    }
    return max;
}


int main()
{
    std::string n1, n2, tag, r1;
    long long i1, i2, r;

    std::cin >> n1 >> n2 >> tag >> r1;

    if (tag == "2")
    {
        std::string t = n2;
        n2 = n1;
        n1 = t;
    }
    
    r = str2num(r1, 10,-1);
    i1 = str2num(n1, r,-1);
    
    i2 = maxr(n2)+1;

    if (str2num(n2, i2,-1) == i1)
    {
        std::cout << i2;
        return 0;
    }
    if (str2num(n2, i2,i1) == -1)
    {
        std::cout << "Impossible";
        return 0;
    }
    if (n2.size() == 1 )
    {
        std::cout << "Impossible";
        return 0;
    }


    long long up = OVER, down = i2;

    if (str2num(n2, up,i1) == i1)
    {
        std::cout << up;
        return 0;
    }

    if (str2num(n2, down,i1) == i1)
    {
        std::cout << down;
        return 0;
    }

    for (;;)
    {
        i2 = (down + up) / 2;
        if (str2num(n2, i2,i1) == i1)
        {
            std::cout << i2;
            break;
        }

        if (down == up)
        {
            std::cout << "Impossible";
            break;
        }

        if (str2num(n2, i2,i1) == -1)
        {
            up = i2;
            continue;
        }
        else if (str2num(n2, i2,i1) < i1)
        {
            if (down == i2)
            {
                std::cout << "Impossible";
                break;
            }
            down = i2;
            continue;
        }
        
    }


    return 0;
}
