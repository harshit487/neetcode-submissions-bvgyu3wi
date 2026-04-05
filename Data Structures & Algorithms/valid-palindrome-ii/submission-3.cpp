class Solution {
public:

    bool isPalindrome(int i , int j , string s)
    {
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return 0;
            }
           
        }
         return 1;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;

        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return isPalindrome(i+1,j,s) || isPalindrome(i,j-1,s);           
                 }
        }
        return 1;
        
    }
};