class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total_sum=0,curr_sum1=0,curr_sum2=0,mxsum_subary=INT_MIN,minsum_subary=INT_MAX;   
        for(auto i:A)
        {
            total_sum+=i; curr_sum1+=i; curr_sum2+=i;
            mxsum_subary=max(mxsum_subary,curr_sum1);
            if(curr_sum1<0) curr_sum1=0;
           minsum_subary=min(curr_sum2,minsum_subary);
            if(curr_sum2>0) curr_sum2=0;
        }
        return (total_sum==minsum_subary)?mxsum_subary:max(mxsum_subary,total_sum-minsum_subary);  
    }
};