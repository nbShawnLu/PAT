#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class v2
{
public:
    vector<int> post;
    vector<int> in;
};



int main()
{
    int n;
    cin >> n;
    vector<v2> cals;
    vector<v2> cals2;
    v2 temp;
    for (int i = 0;i != n;++i)
    {
        int t;
        cin >> t;
        temp.post.push_back(t);
    }
    for (int i = 0;i != n;++i)
    {
        int t;
        cin >> t;
        temp.in.push_back(t);
    }
    cals.push_back(temp);
    int flag = 0;
    while (!cals.empty())
    {
        cals2.clear();
        for (vector<v2>::iterator it = cals.begin();it != cals.end();++it)
        {
            v2 templ, tempr;
            int rs = *(it->post.end() - 1);
            if (flag==0)
            {
                flag = 1;
            }
            else
            {
                cout << ' ';
            }
            cout << rs;
            vector<int>::iterator itrs = find(it->in.begin(), it->in.end(),rs);
            vector<int>::iterator it2 = it->post.begin();

            if (itrs > it->in.begin())
            {
                vector<int>::iterator it3 = it->in.begin();
                
                while (it3 != itrs)
                {
                    templ.post.push_back(*it2);
                    templ.in.push_back(*it3);
                    ++it2;
                    ++it3;
                }
                cals2.push_back(templ);
            }
            if (itrs < it->in.end() - 1)
            {
                vector<int>::iterator it3 = itrs + 1;
                while (*it2 != rs)
                {
                    tempr.post.push_back(*it2);
                    tempr.in.push_back(*it3);
                    ++it2;
                    ++it3;
                }
                cals2.push_back(tempr);
            }
        }
        cals.clear();
        for (vector<v2>::iterator it = cals2.begin();it != cals2.end();++it)
        {
            cals.push_back(*it);
        }
        
    }
    return 0;
}

