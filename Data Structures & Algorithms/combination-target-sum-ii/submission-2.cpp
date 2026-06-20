class Solution {
public:


    void comb(vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans,int size,int index,int sum,int target)
    {
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }
        if(index == size || sum > target) return ;

        temp.push_back(nums[index]);
        comb(nums,temp,ans,size,index+1,sum+nums[index],target);

        temp.pop_back();
           while(index+1 < size &&

              nums[index]==nums[index+1])

        {

            index++;

        }
        comb(nums,temp,ans,size,index+1,sum,target);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        comb(nums,temp,ans,nums.size(),0,0,target);
        return ans;
    }
};
