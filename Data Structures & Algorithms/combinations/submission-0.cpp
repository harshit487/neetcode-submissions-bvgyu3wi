class Solution {
public:

    void combi(int n , int k, vector<int>& temp, vector<vector<int>>& ans , int index)
    {
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
             
        }

        if(index > n)
        {
            return;
        }

        temp.push_back(index);
        combi(n,k,temp,ans,index+1);
        temp.pop_back();
        combi(n,k,temp,ans,index+1);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;
        combi(n,k,temp,ans,1);
        return ans;
    }
};