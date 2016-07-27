#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class book
{
public:
    string ID;
    string title;
    string author;
    vector<string> keywords;
    string publisher;
    string year;
    bool operator<(book& rb);
};

bool book::operator<(book & rb)
{
    return this->ID < rb.ID;
}

int main()
{
    vector<book> books;
    int n;
    char tempc;

    cin >> n;
    cin.get(tempc);

    for (int i = 0;i != n;++i)
    {
        book tempbook;
        string tempstring;
        getline(cin, tempbook.ID);
        getline(cin, tempbook.title);
        getline(cin, tempbook.author);
        getline(cin, tempstring);
        getline(cin, tempbook.publisher);
        getline(cin, tempbook.year);

        
        istringstream iss(tempstring);
        while (iss)
        {
            string sub;
            iss >> sub;
            tempbook.keywords.push_back(sub);
        }
        
        books.push_back(tempbook);

    }

    sort(books.begin(), books.end());

    cin >> n;
    cin.get(tempc);

    for (int i = 0;i != n;++i)
    {
        int t;
        string temps;
        vector<string> rs;

        cin >> t;
        cin.get(tempc);
        cin.get(tempc);
        cout << t << ": ";

        getline(cin, temps);
        cout << temps << '\n';

        switch (t)
        {
        case 1:
            for (vector<book>::iterator it = books.begin();it != books.end();++it)
            {
                if (temps == it->title)rs.push_back(it->ID);
            }
            break;
        case 2:
            for (vector<book>::iterator it = books.begin();it != books.end();++it)
            {
                if (temps == it->author)rs.push_back(it->ID);
            }
            break;
        case 3:
            for (vector<book>::iterator it = books.begin();it != books.end();++it)
            {
                if (find(it->keywords.begin(),it->keywords.end(),temps)!=it->keywords.end())rs.push_back(it->ID);
            }
            break;
        case 4:
            
            for (vector<book>::iterator it = books.begin();it != books.end();++it)
            {
                if (temps == it->publisher)rs.push_back(it->ID);
            }
            break;
        case 5:
            for (vector<book>::iterator it = books.begin();it != books.end();++it)
            {
                if (temps == it->year)rs.push_back(it->ID);
            }
            break;
        default:
            break;
        }


        for (vector<string>::iterator it = rs.begin();it != rs.end();++it)
        {
            cout << *it << '\n';
        }
        if (rs.empty())
        {
            cout << "Not Found\n";
        }
    }

    return 0;
}

