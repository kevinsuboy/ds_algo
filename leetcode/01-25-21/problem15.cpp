#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;
/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        queue<Node *> q;
        Node *res = root;
        q.push(root);
        int size;
        while (!q.empty())
        {
            size = q.size();
            while (size-- > 1)
            {
                root = q.front();
                q.pop();
                root->next = q.front();
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            root = q.front();
            q.pop();
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        return res;
    }
};
int main()
{
    return 0;
}
