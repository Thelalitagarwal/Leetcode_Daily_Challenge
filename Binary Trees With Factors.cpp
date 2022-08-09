class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long ans=0;
        unordered_map<long long, long long> mp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            long long cur=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j])
                    continue;
                long long num1=arr[j];
                long long num2=arr[i]/arr[j];
                cur=(cur+(mp[num1]*mp[num2])%1000000007)%1000000007;
            }
            mp[arr[i]]=cur;
            ans=(ans+cur)%1000000007;
        }
        return ans;
    }
};