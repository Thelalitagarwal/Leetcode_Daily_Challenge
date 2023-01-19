class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1;
        for(int n: A){
            sum = ((sum + n) % K + K) % K;
            mp[sum] ++;
            if(mp[sum] > 1){
                ans += mp[sum] - 1;
            }
        }
        return ans;
    }
};
