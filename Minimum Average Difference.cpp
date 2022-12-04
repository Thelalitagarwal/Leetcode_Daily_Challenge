class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long total=0;
        long long sum=0;
        long long mini=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        for(int i=0;i<nums.size();i++){   
            sum+=nums[i];
            long long t=total-sum;
            long long temp=nums.size()-i-1;
            int ne=0;
            if(temp==0){
                ne=sum/(i+1);
            }
            else{
               ne=(abs(sum/(i+1) - (t/temp)));
            }
            if(mini>ne){
                mini=ne;
                ans=i;
            }
        }
        return ans;
    }
};
