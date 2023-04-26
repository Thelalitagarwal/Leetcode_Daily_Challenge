/*
Link to the " Add Digits " Problem ==>>  https://leetcode.com/problems/add-digits/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/mlfJ7YpaPJM

*/

class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            int ans=0;
            while(num){
                ans=ans+(num%10);
                num/=10;
            }
            num=ans;
        }
        return num;
    }
};