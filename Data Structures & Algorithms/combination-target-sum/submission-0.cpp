class Solution {




public:

    void comb(vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans,int index,int sum,int size,int target)
    {
        if(sum == target) 
        {
            ans.push_back(temp);
            return;
        }
        if(index == size || sum>target) return;

        temp.push_back(nums[index]);
        
        comb(nums,temp,ans,index,sum+nums[index],size,target);
        temp.pop_back();
        comb(nums,temp,ans,index+1,sum,size,target);
        
    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<int>temp;
       vector<vector<int>>ans;
       int n = nums.size();

       comb(nums,temp,ans,0,0,n,target);
       return ans; 
    }
};
