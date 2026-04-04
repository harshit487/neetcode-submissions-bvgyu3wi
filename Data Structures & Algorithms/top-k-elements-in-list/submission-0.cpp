class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>ans;
        int n = nums.size();

        unordered_map<int,int>map;
        for(auto num : nums)
        {
            map[num]++;
        }

        for(auto num : map)
        {
            ans.push_back({num.second,num.first});
        }
        sort(ans.rbegin(),ans.rend());
        vector<int>answer;
        for(int i=0;i<k;i++)
        {
            answer.push_back(ans[i].second);
        }
        return answer;
    }
};
