class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string s : strs)
        {
            encoded = encoded + to_string(s.size()) +"#"+ s;
        }

        return encoded;

    }

    vector<string> decode(string s) {
        vector<string>answer;

        int index = 0;
        while(index < s.size())
        {
            string sz = "";
            while(s[index] != '#')
            {
                sz += s[index];
                index++;
            }
            string ans;
            index++;
            int len = stoi(sz);
            while(len--)
            {
                ans += s[index++];
            }
            answer.push_back(ans);
        }

        return answer;



    }
};
