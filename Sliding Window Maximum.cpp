/*
Link to the "Sliding Window Maximum " Problem ==>> https://leetcode.com/problems/sliding-window-maximum/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/xnuZPbCoNSo

*/

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {

      map<int,int>mp;

      priority_queue<int>pq;

      for(int i=0;i<k-1;i++){
        pq.push(nums[i]);
        mp[nums[i]]++;
      }

      vector<int>ans;

      for(int i=0,j=k-1;j<nums.size();j++){

        mp[nums[j]]++;

        pq.push(nums[j]);

        while(mp[pq.top()]==0){
          pq.pop();
        }

        mp[nums[i]]--;

        ans.push_back(pq.top());
        
        i++;
      }
      return ans;
  }
};