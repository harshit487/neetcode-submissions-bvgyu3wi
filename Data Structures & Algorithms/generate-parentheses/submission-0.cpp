class Solution {
public:
    void backtrack(int open,int close,int n,vector<string>& ans,string temp)
    {
        if((open + close) == 2*n) 
        {
            ans.push_back(temp);
            return;
        }

        if(open < n)
        {
            temp.push_back('(');
            backtrack(open+1,close,n,ans,temp);
            temp.pop_back();
        }

        if(close < open)
        {
            temp.push_back(')');
            backtrack(open,close+1,n,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp = "";
        int open = 0,close = 0;
        backtrack(open,close,n,ans,temp);
        return ans;
    }
};