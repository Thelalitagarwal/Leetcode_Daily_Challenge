/*
Link to the "Remove Colored Pieces if Both Neighbors are the Same Color" Problem ==>> https://leetcode.com/problems/number-of-good-pairs/?envType=daily-question&envId=2023-10-03
   
Link to the complete Explaination Video ==>> https://youtu.be/wPXUmwWKaLo

*/

class Solution{
public:
    
    int numIdenticalPairs(vector<int> &nums){

      int n = nums.size(), cnt = 0;

      unordered_map<int,int> mp;

      for (auto & it: nums)
        mp[it]++;
      
      for (auto & pair: mp) {
        n = pair.second;
        cnt += ((n)*(n-1))/2;
      }
      return cnt;
    }
};