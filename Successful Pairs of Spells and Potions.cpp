/*
Link to the " Successful Pairs of Spells and Potions " Problem ==>>  https://leetcode.com/problems/successful-pairs-of-spells-and-potions/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/L6qK49vm7o8

*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        int p =potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(long long i : spells){

            int s=0;
            int e=p-1;
            int count=0;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(i*potions[mid]>=success){
                    count+=e-mid+1;   
                    e=mid-1;
                }
                else if(i*potions[mid]<success){
                    s=mid+1;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};