class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq;

        for(auto i : t)
        {
            freq[i]++;
        }

        int start = 0;
        int end = 0;
        int n = s.length();
        int m = t.length();
        int min = INT_MAX;
        

        int index;

        while(end < n)
        {
            char ch = s[end];
            freq[ch]--;

            if(freq[ch] >= 0) 
            {
                m--;
            }

            while(m == 0 && start <= end)
            {
                if(min > (end - start) + 1)
                {
                    min = end - start + 1;
                    index = start;
                }
                freq[s[start]]++;
                if(freq[s[start]] > 0)
                {
                    m++;
                }
                start++;
            }
            end++;
        }

        return (min == INT_MAX) ? "" : s.substr(index,min);
    }
};
