class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int,int>map;

        for(auto num : nums)
        {
            map[num]++;
        }

        int freq = (nums.size())/3;
        vector<int>ans;
        for(auto m : map)
        {
            if(m.second > freq)
            {
                ans.push_back(m.first);
            }
        }

        return ans;
        
    }
};