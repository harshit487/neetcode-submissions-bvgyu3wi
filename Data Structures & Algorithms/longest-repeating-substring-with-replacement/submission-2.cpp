class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int start = 0;
        int end = 0;
        unordered_map<char , int> map1;
        int maxf = 0;
        int max_length = 0;

        while(end < n)
        {
            char temp = s[end];
            map1[temp]++;
            maxf = max(maxf , map1[temp]);
            int length = (end - start) + 1;
            if((length - maxf) <= k)
            {
                max_length = max(length , max_length);
                end++;
            }
            else
            {
                map1[s[start]]--;
                start++;
                end++;
            }

        }
        return max_length;
    }
};

 