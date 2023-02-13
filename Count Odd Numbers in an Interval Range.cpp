/*
Link to the "Count Odd Numbers in an Interval Range" Problem ==>>  https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/vVsz2N1OlM4

*/

class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0 && high%2==0){
            return ((high-low)/2);
        }
        return (high-low)/2+1;
    }
};