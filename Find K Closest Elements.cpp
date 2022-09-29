class Solution{
    public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            vector<int>ans;
            int n = arr.size();
            priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>q; 
            for(int i=0 ; i<n ; i++){
                q.push({abs(x-arr[i]) , arr[i]});
            }
            while(k--){
                ans.push_back(q.top().second);
                q.pop();
            }
            sort(ans.begin() , ans.end());
            return ans;
        }
};