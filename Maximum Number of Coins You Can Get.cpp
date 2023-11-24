/*
Link to the "Maximum Number of Coins You Can Get" Problem ==>> https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/?envType=daily-question&envId=2023-11-24
   
Link to the complete Explaination Video ==>> https://youtu.be/8OoBNy6gw2U

*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {

        sort(piles.begin(), piles.end());

        int ans = 0, n = piles.size();
        for (int i = n / 3; i < n; i+=2)
            ans += piles[i];
            
        return ans;
    }
};