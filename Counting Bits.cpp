#Link to vedio Solution: https://www.youtube.com/watch?v=CHurGpL3FA4
#Link to Problem: https://leetcode.com/problems/counting-bits/?envType=daily-question&envId=2023-09-01
class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> ans(n+1,0);

        for(int i = 0; i<=n; i++){
            if(i%2!=0){
                ans[i]=ans[i>>1]+1;
            }
            else{
                ans[i]=ans[i>>1];
            }
        }
        return ans;
    }
};
