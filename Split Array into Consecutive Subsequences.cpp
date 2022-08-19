class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> m,m1;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i :nums){
            if(m[i]==0)
                continue;
            m[i]--;
            if(m1[i-1]>0){
                m1[i-1]--;
                m1[i]++;
            }
            else if(m[i+1]!=0 && m[i+2]!=0){
                m[i+1]--;
                m[i+2]--;
                m1[i+2]++;
            }
            else
                return false;
        }
        return true;
    }
};
