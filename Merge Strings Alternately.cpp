/*
Link to the " Merge Strings Alternately " Problem ==>>  https://leetcode.com/problems/merge-strings-alternately/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/EkJeBKfsJMo

*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string ans = "";
        int p1 = 0, p2 = 0;
        int n = word1.length(), m = word2.length();
        int i = 0;
        while(p1 != n && p2 != m) {
            if (i%2==1) {
                ans += word2[p2++];
            } else {
                ans += word1[p1++];
            }
            i++;
        }
        if (p1 != n) {
            ans += word1.substr(p1, n);
        }
        if (p2 != m) {
            ans += word2.substr(p2, m);
        }
        return ans;
    }
};