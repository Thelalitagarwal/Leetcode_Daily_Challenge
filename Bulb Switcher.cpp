/*
Link to the " Add Digits " Problem ==>>  https://leetcode.com/problems/bulb-switcher/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/XCS71mUD85U

*/

class Solution {
public:
    int bulbSwitch(int n) {
      return int(sqrt(n));
    }
};



/* 2 approach 
class Solution {
public:
    int bulbSwitch(int n) {
      
      int count = 0;
    for (int i = 1; i <= n; i++) {
        int squareRoot = sqrt(i);
        if (squareRoot * squareRoot == i) {
            count++;
        }
    }
    return count;
 
    }
};

*/