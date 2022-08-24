class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        double f=(double)log10(n)/log10(3);
        return ceil(f)==floor(f);
    }
};