class Solution {
public:


    void subs(vector<int>& nums,int index,int size,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(index == size)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        subs(nums,index+1,size,temp,ans);
        temp.pop_back();
        subs(nums,index+1,size,temp,ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        subs(nums,0,n,temp,ans);
        return ans;
    }
};