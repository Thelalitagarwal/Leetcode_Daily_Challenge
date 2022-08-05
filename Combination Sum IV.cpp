class Solution {
public:
    
    int dfs(vector<int>& nums, int target, vector<int>& ways) {
        if(target == 0) 
            return 1;   
        
        if(ways[target] != -1) 
            return ways[target];
        
        int totalWays = 0;
        for(int x : nums) {
            if(target >= x) {
                totalWays += dfs(nums, target-x, ways);
            }
            else{
                break;
            }
        }    
        return ways[target] = totalWays; 
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> ways(target+1,);
        sort(nums.begin(),nums.end());
        return dfs(nums,target,ways);
    }
};