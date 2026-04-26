class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int start = 0;
        int end = n-1;

        while(start < end)
        {
            int mid = start + (end - start)/2;

            if(arr[mid] >= x)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        int i = 0;

        start = end - 1;

        while(i < k)
        {
            if(start == -1)
            {
                end = end + 1;
            } 
            else if(end == n)
            {
                start = start - 1;
            }
            else if(abs(arr[end] - x) < abs(arr[start] - x))
            {
                end = end + 1;
            }
            else
            {
                start = start - 1;
            }

            i++;

        }

        vector<int> answer;
        for(int j = start + 1;j < end;j++)
        {
            answer.push_back(arr[j]);
        }

        return answer;
    }
};