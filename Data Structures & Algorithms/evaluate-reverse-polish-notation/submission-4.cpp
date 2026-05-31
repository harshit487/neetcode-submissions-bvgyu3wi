class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n = tokens.size();
        int result;
 

        for(int i = 0 ;i < n;i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                switch(tokens[i][0])
                {
                    case '+':
                        result = num1 + num2;
                        st.push(result);
                        break;

                    case '-':
                        result = num1 - num2;
                        st.push(result);
                        break;

                    case '*':
                        result = num1 * num2;
                        st.push(result);
                        break;

                    case '/':
                        if(num2 != 0)
                        {
                            result = num1 / num2;
                        }
                        st.push(result);
                        break;

                }
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
