#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "algorithm"
#include <iomanip> 

int bsf(int now, int c2, const std::vector<std::map<int, int>> &next, std::vector<int> &op);
struct path
{
    std::vector<int> p;
    int l;
    int t;
};
std::vector<struct path> paths;
std::vector<int> num;
int main()
{

    int n, m, c1, c2;
    std::cin >> n >> m >> c1 >> c2;

    std::vector<std::map<int, int>> next;

    for (int i = 0; i != n; ++i)
    {
        int temp;
        std::map<int, int> tempm;
        std::cin >> temp;
        num.push_back(temp);
        next.push_back(tempm);
    }
    for (int i = 0; i != m; ++i)
    {
        int f,t,l;
        std::cin >> f >> t >> l;
        next[f].insert(std::make_pair(t, l));
        next[t].insert(std::make_pair(f, l));
    }

    std::vector<int> pp;

    bsf(c1, c2, next, pp);

    int min = -1, max = 0, nn = 0;
    for (std::vector<struct path>::iterator it = paths.begin(); it != paths.end(); ++it)
    {
        if (min == -1 || min > it->l)
        {
            min = it->l;
            max = it->t;
            nn = 1;
        }
        else if (min == it->l)
        {
            if (max < it->t)
            {
                max = it->t;
            }
            ++nn;
        }
    }
    std::cout << nn << ' ' << max;

    return 0;
}
int bsf(int now, int c2, const std::vector<std::map<int, int>> &next, std::vector<int> &op)
{
    std::vector<int> p(op);
    p.push_back(now);

    if (now == c2)
    {
        path r;
        int l = 0, t = 0;
        for (std::vector<int>::iterator it = p.begin(); it != p.end(); ++it)
        {
            r.p.push_back(*it);
            if (it != p.begin())l += (next[*it]).find(*(it-1))->second;
            t += num[*it];
        }
        r.l = l;
        r.t = t;
        paths.push_back(r);
    }
    else
    {
        std::map<int, int> m = next[now];
        for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            if (std::find(p.begin(), p.end(), it->first) == p.end())
            {
                bsf(it->first, c2, next, p);
            }
        }
    }
    return 0;
}