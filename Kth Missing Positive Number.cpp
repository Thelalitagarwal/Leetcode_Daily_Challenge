/*
Link to the " Kth Missing Positive Number " Problem ==>>  https://leetcode.com/problems/kth-missing-positive-number/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/DpEMbKwHJKQ

*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] - mid > k) hi = mid;
            else lo = mid + 1;
        }
        return hi + k;
    }
};