class Solution {
public:
    int MOD=1000000007;
    
    int sumSubarrayMins(vector<int>& arr) { 
        int n = arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(st.size() && arr[i] < arr[st.top()]){
                st.pop();
            }   
            if(st.size()){
                left[i] = i - st.top();
            }
            else{
                left[i] = i+1;
            }
            st.push(i);
        }
        
        while(st.size()) st.pop();
        
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if(st.size()){
                right[i] = st.top() - i;
            }
            else{ 
                right[i] = n - i;
            }
            st.push(i);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            long long total = (left[i]*right[i])%MOD;   
            total = (total*arr[i])%MOD;
            ans = (ans + total)%MOD;
        }
        return ans%MOD;
    }
};