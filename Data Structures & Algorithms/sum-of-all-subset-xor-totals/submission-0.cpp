class Solution {
public:

    void xr(vector<int>& arr , int index , int n , vector<int>& temp , vector<vector<int>>& ans)
    {
        if(index == n)
        {
            ans.push_back(temp);
            return;
        }
        xr(arr , index+1 , n , temp , ans);
        temp.push_back(arr[index]);
        xr(arr , index+1 , n , temp , ans);
        temp.pop_back();
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>> ans;
        xr(nums , 0 , n , temp , ans);
        
        int total = 0;

        for(int i = 0;i < ans.size(); i++)
        {
            int XOR = 0;
            for(int j = 0;j < ans[i].size(); j++)
            {
                XOR = XOR ^ ans[i][j];
            }
            total += XOR;
        }
        return total;
    }
};