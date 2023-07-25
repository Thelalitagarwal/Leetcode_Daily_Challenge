/*
Link to the " Peak Index in a Mountain Array " Problem ==>> https://leetcode.com/problems/peak-index-in-a-mountain-array/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/544u8B_PA34

*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int lo=1,hi=arr.size()-2;
        if(arr.size()>=3)
        {
            while(lo<hi)
            {
                int mid=(lo+hi)/2;
                if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1])
                    return mid;
                else if(arr[mid-1]<arr[mid]&&arr[mid]<arr[mid+1])
                    lo=mid+1;
                else
                    hi=mid;
            }
        }
        return lo;
    }
};