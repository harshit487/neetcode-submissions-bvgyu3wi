class Solution {
public:

    void solve(int i , string& temp,vector<string>& ans,string& s,unordered_set<string>& dict)
    {
        if(i >= s.length())
        {
            ans.push_back(temp);
            return;
        
        }

        for(int j=i;j<s.length();j++)
        {
            string temp1 = s.substr(i,j-i+1);
            if(dict.find(temp1) != dict.end())
            {
                string original = temp;
                if(!temp.empty())
                {
                    temp += ' ';
                }
                temp += temp1;
                solve(j+1,temp,ans,s,dict);
                temp = original;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string &word : wordDict)
        {
            dict.insert(word);
        }

        string temp = "";
        vector<string>ans;
        solve(0,temp,ans,s,dict);
        return ans;
    }
};