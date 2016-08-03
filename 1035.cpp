#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

class account
{
public:
    string name;
    string psw;
};

int main()
{
    vector<account> accounts;
    int n;
    cin >> n;
    for (int i = 0;i != n;++i)
    {
        string name, psw;
        cin >> name >> psw;
        int flag = 0;
        for (string::iterator it = psw.begin();it != psw.end();++it)
        {
            switch (*it)
            {
            case '1':
                *it = '@';
                flag = 1;
                break;
            case '0':
                *it = '%';
                flag = 1;
                break;
            case 'l':
                *it = 'L';
                flag = 1;
                break;
            case 'O':
                *it = 'o';
                flag = 1;
                break;
            default:
                ;
            }         
        }
        if (flag == 1)
        {
            account tempaccount;
            tempaccount.name = name;
            tempaccount.psw = psw;
            accounts.push_back(tempaccount);
        }
    }
    
    if (accounts.size() == 0)
    {
        if (n == 1)
        {
            cout << "There is 1 account and no account is modified";
        }
        else
        {
            cout << "There are " << n << " accounts and no account is modified";
        }
    }
    else
    {
        cout << accounts.size() << '\n';
        for (vector<account>::iterator it = accounts.begin();it != accounts.end();++it)
        {
            cout << it->name << ' ' << it->psw << '\n';
        }
    }

    return 0;
}
