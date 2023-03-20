/*
Link to the " Can Place Flowers " Problem ==>>  https://leetcode.com/problems/can-place-flowers/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/0y480nJVzHs

*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        for (int i = 0; i < flowerbed.size(); i++) {

            if ((flowerbed[i] == 0) && (i == 0 || flowerbed[i-1] == 0) &&
             (i == flowerbed.size() - 1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
        }
        if (n > 0)
            return false;
        return true;
    }
};