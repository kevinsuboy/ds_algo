#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int countUnivalSubtrees(TreeNode *root)
    {
        if (!root)
            return 0;
        int target = root->val, res = 0;
        subProblem(root, res, target);
        return res;
    }

private:
    bool subProblem(TreeNode *root, int &res, int target)
    {
        if (!root)
            return true;
        if (!root->left && !root->right)
        {
            res++;
            return root->val == target;
        }
        int newTarget = root->val == target ? target : root->val;
        bool l = subProblem(root->left, res, newTarget);
        bool r = subProblem(root->right, res, newTarget);
        if (l && r)
            res++;
        return l && r && root->val == target;
    }
};
int main()
{
    return 0;
}
