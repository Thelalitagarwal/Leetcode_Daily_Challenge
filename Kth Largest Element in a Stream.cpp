/*
Link to the " Kth Largest Element in a Stream " Problem ==>> https://leetcode.com/problems/kth-largest-element-in-a-stream/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/RcFFZFsVSEI

*/

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int position;

    KthLargest(int k, vector<int>& nums) {
        position=k;
        for(int i=0;i<nums.size();i++){
            if(pq.size()<k){
                pq.push(nums[i]);
            }
            else if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }    
        }
    }
    int add(int val) {
        if(pq.size()<position){
            pq.push(val);
        }
        else if(pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};
