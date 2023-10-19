/*
Link to the "Backspace String Compare" Problem ==>> https://leetcode.com/problems/backspace-string-compare/?envType=daily-question&envId=2023-10-19
   
Link to the complete Explaination Video ==>> https://youtu.be/mJr8omz-r3M

*/


class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int i = s.size() - 1;
        int j = t.size() - 1;

        int count1 = 0;
        int count2 = 0;

        while(i >= 0 && j >= 0){
            if( s[i] == '#'){
                count1++;
                i--;
            }
            else if( t[j] == '#'){
                count2++;
                j--;
            }
            else if(s[i] != '#' && count1 > 0){
                count1--;
                i--;
            }
            else if( t[j] != '#' && count2 > 0){
                count2--;
                j--;
            }

            else if(s[i] != t[j])
                return false;
            else{
                count1 = 0;
                count2 = 0;
                i--;
                j--;
            }
        }

        while(i>=0){
            if( s[i] == '#'){
                count1++;
                i--;
            }
            else if(s[i] != '#' && count1 > 0){
                count1--;
                i--;
            }
            else
                return false;
        }
        while(j>=0){
            if(t[j] == '#'){
                count2++;
                j--;
            }
            else if(t[j] != '#' && count2 > 0){
                count2--;
                j--;
            }
            else
                return false;
        }
        
        return true;
    }
};