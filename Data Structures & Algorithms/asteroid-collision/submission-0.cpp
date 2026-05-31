class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        int n = asteroids.size();

        for(int i = 0;i < n;i++)
        {
            int c = asteroids[i];
            int flag = 1;
            if(!st.empty())
             
            {
                while(!st.empty() && c < 0 && st.top() >= 0)
                {
                     
                    if(abs(c) > st.top())
                    {
                        st.pop();
                        
                    }
                    else if(abs(c) == st.top())
                    {
                        st.pop();
                        flag = 0;
                        break;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                    
                     
                }
            }
            if(flag)
                st.push(asteroids[i]);

        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};