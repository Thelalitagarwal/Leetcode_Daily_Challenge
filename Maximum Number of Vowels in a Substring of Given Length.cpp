/*
Link to the " Maximum Number of Vowels in a Substring of Given Length " Problem ==>>  https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/w-wBwJSDCCY

*/

class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0,ctemp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                ctemp++;
            if(i-k>=0)
                if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u')
                        ctemp--;            
            if(ctemp>count)
                count=ctemp;
        }
        return count;
    }
};