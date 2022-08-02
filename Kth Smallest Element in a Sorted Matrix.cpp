class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n=m.size();
        int low=m[0][0];
        int high=m[n-1][n-1];
        while(low<high){
            int mid=low+(high-low)/2;
            int count =0;
            for(int i=0;i<n;i++){
                count+=upper_bound(m[i].begin(),m[i].end(),mid)-m[i].begin();
            }
            if(count<k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};