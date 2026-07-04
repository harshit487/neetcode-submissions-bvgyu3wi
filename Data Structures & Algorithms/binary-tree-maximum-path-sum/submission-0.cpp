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
    int maxsum;

    int solve(TreeNode* root)
    {
        if(!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int neeche_milgya = left + right + root->val;

        int koi_ek = max(left,right) + root->val;

        int only_root_acha = root->val;

        maxsum = max({maxsum,neeche_milgya , koi_ek , only_root_acha});

        return max(koi_ek , only_root_acha);
    }

    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        solve(root);
        return maxsum;
    }
};
