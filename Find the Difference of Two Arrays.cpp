/*
Link to the " Find the Difference of Two Arrays " Problem ==>>  https://leetcode.com/problems/find-the-difference-of-two-arrays/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/GX6JfbE3BEg

*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int> num1, vector<int> num2) {

        unordered_set<int> set1;
        vector<vector<int>> ans;
        unordered_set<int> set2;
        for(int i=0;i<num1.size();i++){
            set1.insert(num1[i]);
        }
        for(int i=0;i<num2.size();i++){
            set1.erase(num2[i]);
            set2.insert(num2[i]);
        }
        vector<int> ans1;
        for(auto it:set1){
            ans1.push_back(it);
        }
        ans.push_back(ans1);
        ans1.clear();
        for(int i=0;i<num1.size();i++){
            set2.erase(num1[i]);
        }
        for(auto it:set2){
            ans1.push_back(it);
        }
        ans.push_back(ans1);
        return ans;
    }
};