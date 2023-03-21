/*
Link to the " Number of Zero-Filled Subarrays " Problem ==>>  https://leetcode.com/problems/number-of-zero-filled-subarrays/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/22CfEGAetpQ

*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& n) {

        long long int ans = 0, cnt = 0;
        for(int x: n){
            if(x)
             cnt=0;
            else 
                cnt++;
            ans+=cnt;
        }
        return ans;
    }
};