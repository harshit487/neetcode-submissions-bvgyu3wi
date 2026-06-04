class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string>st;
        string result = "";

        for(int i = 0;i < n;i++){
            string temp = "";
            if(s[i] == ']')
            {
                while(st.top() != "[")
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string y = "";
                while(!st.empty() && st.top() >= "0" && st.top() <= "9")
                {
                    y = st.top() + y;
                    st.pop();
                }
                int x = stoi(y);
                 
                while(x)
                {
                    st.push(temp);
                    x--;
                }
            }
            else
            {
                st.push(string(1, s[i]));
            }
        }
        while(!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};