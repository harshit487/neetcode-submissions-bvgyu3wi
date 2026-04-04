class Solution {
public:
    void merge(vector<int>& arr,int start,int mid,int end)
    {
        vector<int>temp(end-start+1);
        int left = start , right = mid+1 , index = 0;
        while(left <= mid && right <= end)
        {
            if(arr[left] <= arr[right])
            {
                temp[index++] = arr[left++]; 
            }
            else
            {
                temp[index++] = arr[right++];
            }
        }

        while(left <= mid)
        {
            temp[index++] = arr[left++];
        }

        while(right <= end)
        {
            temp[index++] = arr[right++];
        }

        index = 0;
        while(start <= end)
        {
            arr[start++] = temp[index++];

        }
    }

    void mergeSort(vector<int>& arr,int start,int end)
    {
        if(start == end) return;
        int mid = start + (end - start)/2;

        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }

    void sortColors(vector<int>& nums) {
         mergeSort(nums,0,nums.size()-1);
    
    }
};
 
     
       
     