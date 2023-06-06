/*
Link to the " Can Make Arithmetic Progression From Sequence " Problem ==>> https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/QfojPZ1JDo4

*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i = 1; i < arr.size()-1; i++){
            if(2*arr[i] != arr[i-1]+arr[i+1])
                return false;
        }
        return true;
    }
};3