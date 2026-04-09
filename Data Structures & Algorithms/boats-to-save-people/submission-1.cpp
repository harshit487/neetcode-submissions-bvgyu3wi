class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int start = 0;
        int end = n-1;

        int boat = 0;
        while(start <= end)
        {
            int sum = people[start] + people[end];
             
            if(sum <= limit)
            {
                boat++;
                start++;
                end--;
            }
            else
            {
                end--;
                boat++;
            }

            
        }
        return boat;
    }
};