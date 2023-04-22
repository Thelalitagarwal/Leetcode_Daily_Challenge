/*
Link to the " Minimum Insertion Steps to Make a String Palindrome " Problem ==>>  https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/PF8cW7k8BT8

*/


class Solution {
public:
    int minInsertions(string s) {

        int n=s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        int t[n+1][n+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0)
                    t[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==rev[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return n-t[n][n];
    }
};