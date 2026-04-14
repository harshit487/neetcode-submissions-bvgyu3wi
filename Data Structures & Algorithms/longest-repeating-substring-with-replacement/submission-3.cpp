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
    map1[s[end]]++;
    maxf = max(maxf, map1[s[end]]);

    if((end-start+1) - maxf > k)
    {
        map1[s[start]]--;
        start++;
    }

    max_length = max(max_length, end-start+1);
    end++;
}

        
        return max_length;
    }
};

 