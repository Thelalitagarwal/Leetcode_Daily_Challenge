class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int one = 2;
        int two = 1;
        int ways = 0;
        
        for(int i=2; i<n; i++){
            ways = one + two;
            two = one;
            one = ways;
        }
        return ways;
    }
};