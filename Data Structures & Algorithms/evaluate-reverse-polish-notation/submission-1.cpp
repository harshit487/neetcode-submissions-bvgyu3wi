class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        int n = s.size();

        int p = 0;

        while(p<n)
        {
            if(s[p] != "+" && s[p] != "-" && s[p] != "*" && s[p] != "/")
            {
                
                st.push(stoi(s[p]));
            }

            else
            {
                int a1 = st.top();
                st.pop();
                int a2 = st.top();
                st.pop();
                
                if(s[p] == "+")
                    st.push(a2 + a1);

                else if(s[p] == "-")
                    st.push(a2 - a1);

                else if(s[p] == "*")
                    st.push(a2 * a1);

                else 
                    st.push(a2 / a1);

                

            }
            p++;
        }
        
        return st.top();
    }
}; 