/*
Link to the "Is Subsequence" Problem ==>> https://leetcode.com/problems/is-subsequence/description/?envType=daily-question&envId=2023-09-22 
   
Link to the complete Explaination Video ==>> https://youtu.be/QrLKHEKYdiI

*/

class Solution {
    int isSubSequence(string& s1, string& s2, int i, int j)
    {
        if (i == 0 || j == 0) {
            return 0;
        }
        else if (s1[i - 1] == s2[j - 1]) {
            return  1 + isSubSequence(s1, s2, i - 1, j - 1);
        }
        return  isSubSequence(s1, s2, i, j - 1);
    }
 
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m > n) {
            return false;
        }
        if (isSubSequence(s, t, m, n) == m) {
            return true;
        }
        return false;
    }
};