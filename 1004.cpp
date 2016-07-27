#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "algorithm"
#include <iomanip> 

class snode
{
public:
    int val;
    std::vector<snode*> child;
    snode(int v);
};

snode::snode(int v)
{
    val = v;
}
snode* sfind(std::vector<snode *> nodes, int a)
{
    for (std::vector<snode *>::iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        if ((*it)->val == a)
        {
            return *it;
        }
    }
    return NULL;
}
int main()
{
    int n, m;
    std::vector<snode *> nodes;

    snode* root = new snode(1);
    nodes.push_back(root);
    std::cin >> n >> m;
    for (int i = 0; i != m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b;
        snode* node = sfind(nodes, a);
        if (node == NULL)
        {
            snode* t = new snode(a);
            nodes.push_back(t);
            node = t;
        }
        
        for (int j = 0; j != b; ++j)
        {
            std::cin >> c;
            if (sfind(nodes, c) == NULL)
            {
                snode* t = new snode(c);
                nodes.push_back(t);
                node->child.push_back(t);
            }
            else
            {
                node->child.push_back(sfind(nodes, c));
            }
        }
    }

    std::vector<snode*> temp;
    std::vector<snode*> temp2;
    temp.push_back(root);
    int rs;
    int flag = 0;
    while (!temp.empty())
    {
        rs = 0;
        temp2.clear();
        for (std::vector<snode*>::iterator it = temp.begin(); it != temp.end(); ++it)
        {
            if ((*it)->child.empty())
            {
                ++rs;
            }
            else
            {
                for (std::vector<snode*>::iterator it2 = (*it)->child.begin(); it2 != (*it)->child.end(); ++it2)
                {
                    temp2.push_back(*it2);
                }
            }
        }
        temp.clear();
        for (std::vector<snode*>::iterator it = temp2.begin(); it != temp2.end(); ++it)
        {
            temp.push_back(*it);
        }
        if (flag == 0)
        {
            flag = 1;
        }
        else
        {
            std::cout << ' ';
        }
        std::cout << rs;
    }


    return 0;
}
