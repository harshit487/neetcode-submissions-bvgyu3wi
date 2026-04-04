class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>temp;

        for(int i=0;i<position.size();i++)
        {
            temp.push_back({position[i],speed[i]});
        }

        sort(temp.rbegin(),temp.rend());
        vector<double>st;

        for(auto p : temp)
        {
            st.push_back((double)(target-p.first)/p.second);

            if(st.size() >= 2 && st.back() <= st[st.size() - 2])
            {
                st.pop_back();
            }
        }
        return st.size();

    }
};