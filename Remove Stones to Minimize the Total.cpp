/*
Link to the "Remove Stones to Minimize the Total" Problem ==>>  https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/ysvYRJP0E6o 

*/
class Solution {
public:
       int minStoneSum(vector<int>& A, int k) {
           
            priority_queue<int> pq(A.begin(), A.end());
            int res = accumulate(A.begin(), A.end(), 0);
            while (k--) {
                int a = pq.top();
                pq.pop();
                pq.push(a - a / 2);
                res -= a / 2;
            }
            return res;
    }
};