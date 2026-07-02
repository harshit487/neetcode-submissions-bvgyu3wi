class Solution {
public:

    bool bst(TreeNode* root,int& prev)
    {
        if(!root) return 1;
        bool l = bst(root->left,prev);
        if(l == 0) return 0;
        if(root->val <= prev) return 0;
        prev = root->val;
        return bst(root->right , prev);
    }

    bool isValidBST(TreeNode* root) {
        
        int prev = INT_MIN;
        return bst(root,prev);
    }
};