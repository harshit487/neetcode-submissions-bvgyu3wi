class Solution {
public:

    void gen(vector<string>& ans , string temp , int n , int left , int right)
    {

        if((left + right) == 2*n)
        {
            ans.push_back(temp);
            return;
        }

        if(left < n)
        {
            temp.push_back('(');
            gen(ans,temp,n,left+1,right);
            temp.pop_back();
        }

        if(right < left)
        {
            temp.push_back(')');
            gen(ans,temp,n,left,right+1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp = "";
        
        gen(ans , temp , n , 0 , 0);
        return ans;
    }
};
