class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> output(k);
        int prefixMod = 0;
        int res = 0;
        output[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            prefixMod = (prefixMod + nums[i] % k + k) % k;
            res = res + output[prefixMod];
            output[prefixMod]++;
        }
        return res;
    }
};