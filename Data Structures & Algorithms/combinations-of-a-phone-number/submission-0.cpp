class Solution {
public:
        unordered_map<char,string>mp;


    void solve(string& digits , string& temp , vector<string>& ans, int idx )
    {
        if(idx >= digits.length())
        {
            ans.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];

        for(int i = 0;i < str.length();i++)
        {
            temp.push_back(str[i]);
            solve(digits,temp,ans,idx+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        string temp = "";
        vector<string>ans;

     

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(digits , temp , ans , 0);
        return ans;
    }
};
