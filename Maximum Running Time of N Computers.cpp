/*
Link to the " Maximum Running Time of N Computers " Problem ==>> https://leetcode.com/problems/maximum-running-time-of-n-computers/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/SWf-6hbsMZ8

*/

class Solution {
private:
    bool isValid(long long time, vector<int>& batteries, int n){

        long long total = 0;
        
        for(int i=0; i<batteries.size(); i++){
            total += min(time,1LL*batteries[i]);
        }
        return total >= time*n;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long low = 1;

        long long high = 0;

        for(int i=0; i<batteries.size(); i++){
            high += batteries[i];
        }

        high = high/n;

        long long ans = 0;

        while(low <= high){

            long long mid = (high + low) / 2;

            if(isValid(mid,batteries,n)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};