class Solution {
public:

    int find(vector<int>& inorder , int target , int start , int end)
    {
        for(int i = start ;i <= end;i++)
        {
            if(inorder[i] == target) return i;
        }
        return -1;
    }

    TreeNode* tree(vector<int>& inorder , vector<int>& preorder , int instart , int inend , int index)
    {

        if(instart > inend) return nullptr;

        TreeNode* root = new TreeNode(preorder[index]);
        int pos = find(inorder , preorder[index] , instart , inend);
        root->left = tree(inorder , preorder , instart , pos-1,index+1);
        root->right = tree(inorder , preorder, pos+1 , inend , index+(pos-instart)+1);
        return root;


    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        int instart = 0;
        int inend = inorder.size() - 1;
        return tree(inorder , preorder , instart , inend , index);
    }
};