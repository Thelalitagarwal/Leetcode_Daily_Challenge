/*
Link to the "Number of 1 Bits" Problem ==>> https://leetcode.com/problems/number-of-1-bits/description/?envType=daily-question&envId=2023-11-29
   
Link to the complete Explaination Video ==>> https://youtu.be/ZUU5EmWQVIE

*/


class Solution {
public:
    int hammingWeight(uint32_t n) {

        int count = 0;

        while (n) {
            
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};