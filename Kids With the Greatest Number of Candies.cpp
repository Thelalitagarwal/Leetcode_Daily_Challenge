/*
Link to the " Kids With the Greatest Number of Candies " Problem ==>>  https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/_tH2KNcUb04

*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        int maxi=0;
        maxi = *max_element(candies.begin(),candies.end());
        vector<bool> result;
        for(int i=0;i<candies.size();i++){

            if((candies[i]+extraCandies)>=maxi){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};