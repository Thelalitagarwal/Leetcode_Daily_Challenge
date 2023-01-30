/*
Link to the "N-th Tribonacci Number" Problem ==>>  https://leetcode.com/problems/n-th-tribonacci-number/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/JA9sXqmDKmw 

*/
class Solution {
public:
    int tribonacci(int n) {
        int t1=0;
        int t2=1;
        int t3=1;
        int ans=0;
        if(n==0){
            return t1;
        }
        else if(n==1 || n==2){
            return t2;
        }
        int i=3;
        while(i<=n){
            ans=t1+t2+t3;
            t1=t2;
            t2=t3;
            t3=ans;
            i++;
        }
        return ans;
    }
};