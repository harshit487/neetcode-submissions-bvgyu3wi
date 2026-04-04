class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        vector<int>ans(temp.size(),0);

        for(int i=0;i<temp.size();i++)
        {
            int x = temp[i];
            while(!st.empty() && x > temp[st.top()])
            {
                int a = i-st.top();
                ans[st.top()] = a;
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};