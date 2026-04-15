class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<int> freq1(26,0);

        for(int i = 0 ; i < n1 ; i++)
        {
            freq1[s1[i] - 'a']++;
        }

        int start = 0;
        int end = n1 - 1;
    

        while(end < n2)
        {
            vector<int> freq2(26,0);
            for(int i = start ; i <= end ; i++)
            {
                freq2[s2[i] - 'a']++;

            }
            if(freq1 == freq2) return true;
            start++;
            end++;
        }
        return false;
    }
};
