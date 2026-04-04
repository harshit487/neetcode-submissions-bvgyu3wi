class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded = "";
        for(auto sz : strs)
        {
            encoded = encoded +  to_string(sz.size()) + "#" + sz;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>answer;

        int index = 0;
        while(index<s.size())
        {
            string sz = "";
             while(s[index]!='#')
             {
                sz += s[index];
                index++;
             }
             index++;
             int len = stoi(sz);
             string ans;
             while(len--)
             {
                ans += s[index++];

             }
             answer.push_back(ans);
        }
        return answer;

        
    }
};
