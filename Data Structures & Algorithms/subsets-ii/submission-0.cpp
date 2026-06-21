class Solution {
public:

    void subs(vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans , int index)
    {
        if(index == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        subs(nums,temp,ans,index+1);
        temp.pop_back();
        index = index+1;
        while(index < nums.size() && nums[index] == nums[index-1])
        {
            index++;
        }
        subs(nums,temp,ans,index);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        subs(nums,temp,ans,0);
        return ans;
    }
};