class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        int n = strs.size();
        if(n == 1 ) return s;

        int m = INT_MAX;
        for(int i = 1;i<n;i++)
        {
            int k = 0;
            for(int j = 0;j<s.size();j++)
            {
                if(strs[i][j] == s[j])
                {
                    k++;
                }
                else
                {
                    break;
                }
            }
            m = min(k,m);
        }
        return m==INT_MAX ? "" : s.substr(0,m);
    }
};