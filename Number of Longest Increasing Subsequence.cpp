/*
Link to the " Number of Longest Increasing Subsequence " Problem ==>> https://leetcode.com/problems/number-of-longest-increasing-subsequence/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/qrSRqGHaSGQ

*/

class Solution {
public:
     int findNumberOfLIS(vector<int>& nums) {
          int n = nums.size();

          vector<int> dp( n , 1) , cnt( n ,1);

          int maxi = 1;
          int nos =0 ;

          for( int i =0 ; i< n ;i++){
              
               for( int prev= 0 ; prev<i; prev++){

                    if( nums[prev] < nums[i] && 1+ dp[prev] > dp[i] ){
                         dp[i]  = 1 + dp[prev];
                         cnt[i] = cnt[prev];
                    }
                    else if(nums[prev] < nums[i] && 1+ dp[prev] == dp[i] ){
                         cnt[i] +=cnt[prev];
                    }
               }
          maxi = max( maxi , dp[i] );
          }
          for( int i =0 ;i<n ; i++){
               if( dp[i] ==maxi){
                    nos+=cnt[i];
               }
          }      
     return nos;
     }
};