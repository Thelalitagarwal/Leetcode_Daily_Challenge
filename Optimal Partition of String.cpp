/*
Link to the " Optimal Partition of String " Problem ==>>  https://leetcode.com/problems/optimal-partition-of-string/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/K9p6PJeT_DE

*/

class Solution {
public:
    int partitionString(string s) {

        int count  = 0, right = 0;
        int n = s.size();
        int mask = 0;
        while(right < n){
            int pos = (s[right] - 'a');
            if(mask & (1 << pos)){
                mask = 0;
                count++;
            }
            mask |= (1 << pos);
            right++;
        }
        if(mask) 
            count++;

        return count;
    }
};