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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
            return NULL;
        int i = 0;
        const int N = inorder.size() - 1;
        unordered_map<int, int> hash;
        for (; i <= N; i++)
            hash[inorder[i]] = i;
        i = hash[postorder.back()];
        TreeNode *root = new TreeNode(postorder.back());
        postorder.pop_back();
        root->right = subproblem(i + 1, N, postorder, hash);
        root->left = subproblem(0, i - 1, postorder, hash);
        return root;
    }

private:
    TreeNode *subproblem(int l, int r, vector<int> &postorder, unordered_map<int, int> &hash)
    {
        if (l > r || postorder.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(postorder.back());
        int i = hash[postorder.back()];
        postorder.pop_back();
        root->right = subproblem(i + 1, r, postorder, hash);
        root->left = subproblem(l, i - 1, postorder, hash);
        return root;
    }
};
int main()
{
    return 0;
}
