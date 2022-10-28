class Solution {
 public:
     int NthTerm(int n){
         
        long long int a=2;
        long long int b=1000000007;
        if(n==1) return 2;
        for(int i=2;i<=n;i++){
               a=(a*i+1)%b;
        }
       return a%b;
     }
};