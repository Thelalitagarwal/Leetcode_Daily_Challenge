/*
Link to the "Majority Element II" Problem ==>> https://leetcode.com/problems/majority-element-ii/?envType=daily-question&envId=2023-10-05
   
Link to the complete Explaination Video ==>> https://youtu.be/CgoiWJU5FIw

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int,int> freq;

        int n = nums.size();

        vector<int> ans;
        
        for(auto it : nums) {
         freq[it]++;
        }

        for(auto it : freq){
            if(it.second > floor(n/3))
               ans.push_back(it.first);
         }
         return ans;
    }
};