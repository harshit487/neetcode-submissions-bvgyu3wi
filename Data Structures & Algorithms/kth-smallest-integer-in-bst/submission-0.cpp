
class Solution {
public:

    void ksmall(TreeNode* root,int& k ,int& ans)
    {
        if(!root) return;
        ksmall(root->left,k,ans);
        k--;
        if(k==0) {
            ans = root->val;
            return;
        }
        ksmall(root->right,k,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans;
        ksmall(root,k,ans);
        return ans;
    }
};