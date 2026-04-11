class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int first = 0;
        int second = 0;
        vector<bool> flag(255,0);

        int maxi = 0;
        while(second < n)
        {
            if(flag[s[second]])
            {
                flag[s[first]] = 0;
                first++;
            }
            else
            {
                flag[s[second]] = 1;
                maxi = max(maxi,(second-first+1));
                second++;
            }
        }
        return maxi;
    }
};
