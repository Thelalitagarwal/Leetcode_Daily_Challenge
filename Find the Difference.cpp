/*
Link to the "Find the Difference" Problem ==>> https://leetcode.com/problems/find-the-difference/description/?envType=daily-question&envId=2023-09-25 
   
Link to the complete Explaination Video ==>> https://youtu.be/V0_3dDXmOKw

*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<n; i++) 
            if(s[i]!=t[i])  
                return t[i];
        return t[n];
    }
};