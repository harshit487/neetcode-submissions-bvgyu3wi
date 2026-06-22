class Solution {
public:


    bool isPalin(string s,int l,int r)
    {
        while(l < r)
        {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }


    void palin(string s,vector<string>& temp,vector<vector<string>>& ans,int idx)
    {
        if(idx == s.length())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = idx ;i < s.length();i++)
        {
            if(isPalin(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                palin(s,temp,ans,i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;

        palin(s,temp,ans,0);      
        return ans;  
    }
};