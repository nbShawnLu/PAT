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

class node
{
public:
    int val;
    int left;
    int right;
    int hight;
    int father;
};

typedef vector<node> tree;

void setc(tree & tr, int father, int child, bool left)
{
    int h = 1;
    if (left)
        tr[father].left = child;
    else
        tr[father].right = child;
    if (tr[father].left != -1 && tr[tr[father].left].hight + 1 > h)
    {
        h = tr[tr[father].left].hight + 1;
    }
    if (tr[father].right != -1 && tr[tr[father].right].hight + 1 > h)
    {
        h = tr[tr[father].right].hight + 1;
    }
    tr[father].hight = h;
    if (child != -1)
        tr[child].father = father;
}
void nodeinsert(int v, tree & tr, int & root)
{
    node tnode;
    tnode.val = v;
    tnode.hight = 1;
    tnode.left = -1;
    tnode.right = -1;
    tnode.father = -1;
    if (root == -1)
    {
        tnode.father = -1;
        root = 0;
        tr.push_back(tnode);
    }
    else
    {
        int travel = root;
        while (tnode.father == -1)
        {
            if (v > tr[travel].val)
            {
                if (tr[travel].right == -1)
                {
                    tnode.father = travel;
                    tr.push_back(tnode);
                    tr[travel].right = tr.size() - 1;
                }
                else
                {
                    travel = tr[travel].right;
                    continue;
                }
            }
            else
            {
                if (tr[travel].left == -1)
                {
                    tnode.father = travel;
                    tr.push_back(tnode);
                    tr[travel].left = tr.size() - 1;
                }
                else
                {
                    travel = tr[travel].left;
                    continue;
                }
            }
        }
    }
    int travel = tr.size() - 1;
    while (tr[travel].father != -1)
    {
        if (tr[tr[travel].father].hight < tr[travel].hight + 1)
            tr[tr[travel].father].hight = tr[travel].hight + 1;
        travel = tr[travel].father;
    }
}
void nodebalance(tree & tr, int & root)
{
    if (root == -1)return;
    int travel = root;
    int flag1 = 0, flag2 = 0;
    int n1 = 0, n2 = 0;
    if (tr[travel].left != -1)
    {
        n1 = tr[tr[travel].left].hight;
    }
    if (tr[travel].right != -1)
    {
        n2 = tr[tr[travel].right].hight;
    }
    if (n1 - n2 > 1)
    {
        flag1 = 1;
        travel = tr[travel].left;
    }
    else if (n2 - n1 > 1)
    {
        flag1 = 0;
        travel = tr[travel].right;
    }
    else return;
    n1 = 0;n2 = 0;
    if (travel != -1 && tr[travel].left != -1)
    {
        n1 = tr[tr[travel].left].hight;
    }
    if (travel != -1 && tr[travel].right != -1)
    {
        n2 = tr[tr[travel].right].hight;
    }
    if (n1 > n2)
    {
        flag2 = 1;
    }
    else if (n2 > n1)
    {
        flag2 = 0;   
    }
    else return;
    if (flag1&&flag2)
    {
        setc(tr, root, tr[travel].right, true);
        setc(tr, travel, root, false);
        root = travel;
    }
    if (flag1 && (!flag2))
    {
        int k2 = tr[travel].right;
        setc(tr, root, tr[k2].right, true);
        setc(tr, travel, tr[k2].left, false);
        setc(tr, k2, root, false);
        setc(tr, k2, travel, true);
        root = k2;    
    }
    if ((!flag1)&&(!flag2))
    {
        setc(tr, root, tr[travel].left, false);
        setc(tr, travel, root, true);
        root = travel;
    }
    if ((!flag1) && flag2)
    {
        int k2 = tr[travel].left;
        setc(tr, root, tr[k2].left, false);
        setc(tr, travel, tr[k2].right, true);
        setc(tr, k2, root, true);
        setc(tr, k2, travel, false);
        root = k2;
    }
    tr[root].father = -1;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    tree tr;
    int root = -1;
    for (int i = 0;i != n;++i)
    {
        int t;
        cin >> t;
        nodeinsert(t, tr, root);
        
        nodebalance(tr, tr[root].left);
        nodebalance(tr, tr[root].right);
        nodebalance(tr, root);
    }
    
    cout << tr[root].val;
    return 0;
}

