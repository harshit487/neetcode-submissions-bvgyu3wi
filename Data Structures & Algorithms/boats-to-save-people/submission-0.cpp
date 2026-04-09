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
            if(people[end] == limit)
            {
                end--;
                boat++;
            }
            else if(sum <= limit)
            {
                boat++;
                start++;
                end--;
            }
            else if(people[end] < limit)
            {
                end--;
                boat++;
            }

            else
            {
                end--;
            }
        }
        return boat;
    }
};