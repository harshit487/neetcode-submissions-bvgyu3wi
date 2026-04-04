class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            map[nums[i]] = i;
        }
        vector<int>answer(2);
        for(int i =0;i<n;i++)
        {
            int ans = target - nums[i];
            if(map.find(ans)!= map.end() && map[ans]!=i)
            {
                answer[0] = i;
                answer[1] = map[ans];
                break;
            }
        }

        return answer;
    }
};
