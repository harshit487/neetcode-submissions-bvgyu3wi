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

    int height(TreeNode* root)
    {
        if(!root) return 0;

        return 1 + max(height(root->left),height(root->right));
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        int l = height(root);
        queue<TreeNode*>q;
        vector<vector<int>>ans(l);

        q.push(root);
        int i = 0;
        
        
        while(!q.empty())
        {
             int n = q.size();

             while(n--)
             {
                TreeNode* temp = q.front();
                q.pop();

                ans[i].push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
             }
             i++;
            
        }
        return ans;
    }
};