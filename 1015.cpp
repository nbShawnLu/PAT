#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "algorithm"
#include "iomanip"

using namespace std;

string reversestr(string & s)
{
    string rs;
    for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
    {
        rs.push_back(*it);
    }
    return rs;
}

int str2num(string & s, int r)
{
    int rs = 0;
    for (string::iterator it = s.begin(); it != s.end(); ++it)
    {
        rs *= r;
        if (*it >= '0'&&*it <= '9')
        {
            rs += *it - '0';
        }
        else
        {
            rs += *it - 'a' + 10;
        }
    }
    return rs;
}

string num2str(int n, int r)
{
    string rs;
    int temp;
    if (n == 0)
    {
        rs = "0";
    }
    while (n != 0)
    {
        temp = n%r;
        if (temp <= 9)
        {
            rs.push_back(temp + '0');
        }
        else
        {
            rs.push_back(temp - 10 + 'a');
        }
        n /= r;
    }
    rs = reversestr(rs);
    return rs;
}

bool isprime(int n)
{
    if (n < 2)return false;
    for (int i = 2; i*i <= n; ++i)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int a, b, c;
    for (;;)
    {
        cin >> a;
        if (a < 0)break;
        cin >> b;
        if (a < 2)
        {
            cout << "No\n";
            continue;
        }
        string temp = num2str(a, b);
        temp = reversestr(temp);
        c = str2num(temp,b);
        if (isprime(a) && isprime(c))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}