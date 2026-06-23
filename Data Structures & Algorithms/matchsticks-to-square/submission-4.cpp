class Solution {
public:

    bool msq(vector<int>& matchsticks , vector<int>& sides , int length , int index)
    {
        if(index == matchsticks.size())
        {
            return true;
        }

        for(int i = 0;i < sides.size();i++)
        {
            if(sides[i] + matchsticks[index] <= length)
            {
                sides[i] += matchsticks[index];
            
            if(msq(matchsticks,sides,length,index+1))
            return true;

            sides[i] -= matchsticks[index];
        }
        }
        return false;
    }


    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        sort(matchsticks.begin(),matchsticks.end());
        reverse(matchsticks.begin(),matchsticks.end());
        for(int i = 0;i < n;i++)
        {
            sum += matchsticks[i];
        }
        vector<int>sides(4,0);
        if(sum%4 == 0)
            return msq(matchsticks,sides,sum/4,0);

        return false;
    }
};