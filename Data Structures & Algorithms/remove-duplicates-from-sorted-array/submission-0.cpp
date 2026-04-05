class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int i = 0;
        int j = 1;

        while(j < nums.size())
        {
            if(nums[i] != nums[j])
            {
                i = j;
                k++;
                j++;
            }
            else
            {
                nums.erase(nums.begin() + j);
                
            }
        }
        return k;
    }
};