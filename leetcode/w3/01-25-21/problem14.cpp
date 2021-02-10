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
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return NULL;
        reverse(preorder.begin(), preorder.end());
        int i = 0;
        const int N = inorder.size();
        unordered_map<int, int> hash;
        for (; i < N; i++)
            hash[inorder[i]] = i;
        i = hash[preorder.back()];
        TreeNode *root = new TreeNode(preorder.back());
        preorder.pop_back();
        root->left = subproblem(0, i - 1, preorder, inorder, hash);
        root->right = subproblem(i + 1, N, preorder, inorder, hash);
        return root;
    }

private:
    TreeNode *subproblem(int l, int r, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &hash)
    {
        if (l > r || preorder.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder.back());
        int i = hash[preorder.back()];
        preorder.pop_back();
        root->left = subproblem(l, i - 1, preorder, inorder, hash);
        root->right = subproblem(i + 1, r, preorder, inorder, hash);
        return root;
    }
};
int main()
{
    return 0;
}
