/*
Link to the " Candy " Problem ==>> https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2023-09-13 
   
Link to the complete Explaination Video ==>> https://youtu.be/dmy_1QIUk4U

*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = size(ratings);

        vector<int> candies(n, 1);

        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;



        for (int i = n-2; i >= 0; --i)
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1]+1);
        
        int ans = 0;
        for (int& c : candies)
            ans += c;
            
        return ans;
    }
};