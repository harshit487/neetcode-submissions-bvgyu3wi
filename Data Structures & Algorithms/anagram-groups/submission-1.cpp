class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;

        int n = strs.size();

        for(int i = 0;i<n;i++)
        {
            string s = strs[i];
            sort(s.begin(),s.end());
            m[s].push_back(strs[i]);
        }

        vector<vector<string>> answer;
        for(auto j : m)
        {
            answer.push_back(j.second);
        }
        return answer;
    }
};
