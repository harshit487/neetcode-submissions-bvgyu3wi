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

class Solution {
public:

    void good(TreeNode* root , int& ans,int l)
    {
        if(!root) return;
        if(l <= root->val)
        {
            l = root->val;
            ans++;
        }
        good(root->left,ans,l);
        good(root->right,ans,l);
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int ans = 0;

        int l = INT_MIN;

        good(root,ans,l);
        return ans;
    }
}; 