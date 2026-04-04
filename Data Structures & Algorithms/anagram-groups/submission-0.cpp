class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(auto str : strs)
        {
            vector<int>freq(26,0);
            for(char c : str)
            {
                freq[c-'a']++;
            }
            string key;
            for(int count : freq)
            {
                key += to_string(count) + "#";
            }
            map[key].push_back(str);
        }
        vector<vector<string>> answer;
        for(auto pair : map)
        {
            answer.push_back(pair.second);
        }
        return answer;
    }
};
