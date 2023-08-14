/*
Link to the "Kth Largest Element in an Array" Problem ==>> https://leetcode.com/problems/kth-largest-element-in-an-array/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/QLCGmSjD9c8

*/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int size = nums.size();

        priority_queue <int , vector<int> , greater<int> > pq ;
        for(int i =0 ; i<size ; i++){
            pq.push(nums[i]);
            if(pq.size() >k)
                pq.pop();
        }
        return pq.top() ;
    }
};