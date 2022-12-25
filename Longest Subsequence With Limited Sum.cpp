class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)nums[i]+=nums[i-1];
        vector<int> ans;
        for(int i:queries){
            int res=upper_bound(nums.begin(),nums.end(),i)-nums.begin();
            ans.push_back(res);
        }
        return ans;
    }
};