/*
Link to the " Group the People Given the Group Size They Belong To " Problem ==>> https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/?envType=daily-question&envId=2023-09-11 
   
Link to the complete Explaination Video ==>> https://youtu.be/6ikOxMQrb24

*/

class Solution {
public:
       vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        vector<vector<int>> ans;

        unordered_map<int, vector<int>> dict; 

        for (int i=0; i<groupSizes.size(); i++) {

            int key = groupSizes[i];

            dict[key].push_back(i);
            
            if (dict[key].size() == key) { 
                ans.push_back(dict[key]);
                dict.erase(key);
            }
        }
        return ans;
    }
};