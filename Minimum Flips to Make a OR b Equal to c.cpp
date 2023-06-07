/*
Link to the " Minimum Flips to Make a OR b Equal to c " Problem ==>> https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/upgnDo9eA-k

*/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while (a > 0 || b > 0 || c > 0) {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;
            if ((bitA | bitB) != bitC) {
                if (bitC == 1) {
                    flips++;
                } else {
                    flips += (bitA + bitB);
                }
            }   
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};