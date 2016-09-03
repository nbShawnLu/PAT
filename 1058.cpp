#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

class num
{
public:
    int a = 0, b = 0, c = 0;
    num operator+(num & that);
};

num num::operator+(num & that)
{
    num rs;

    rs.c = this->c + that.c;
    if (rs.c >= 29)
    {
        rs.b = 1;
        rs.c -= 29;
    }

    rs.b += this->b + that.b;
    if (rs.b >= 17)
    {
        rs.a = 1;
        rs.b -= 17;
    }

    rs.a += this->a + that.a;
    return rs;
}
istream & operator >>(istream &input, num & n)
{
    char dot;
    input >> n.a >> dot >> n.b >> dot >> n.c;
    return input;
}
ostream & operator <<(ostream & output, num & n)
{
    output << n.a << '.' << n.b << '.' << n.c;
    return output;
}
int main()
{
    ios::sync_with_stdio(false);
    num n1, n2, ns;
    cin >> n1 >> n2;
    ns = n1 + n2;
    cout << ns;
    return 0;
}

