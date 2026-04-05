class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0 , j = n-1;

        while(i<j)
        {
            char a = s[i];
            char b = s[j];

            if(!isalnum(a))
            {
                i++;
                continue;
            }
            else if(!isalnum(b))
            {
                j--;
                continue;
            }
            else
            {
                if(tolower(a) == tolower(b))
                {
                    i++;
                    j--;
                }
                else
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};
