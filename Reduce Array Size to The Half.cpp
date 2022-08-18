class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ans=0;
        int n1=0;
        vector<int> v;
        int n= arr.size();
        unordered_map<int, int> um;
        for(int i=0; i< n; i++)  
        {
          um[arr[i]]++;
        }
    
       for (auto x : um)
       {
           v.push_back(x.second);
           
       }
        if(v.size()==1)return 1;
        sort(v.begin(), v.end());
        for(int i=v.size()-1; i>=0; i--)
        {
            if(ans>=n/2){
              return n1;
        } 
        n1++;
        ans= ans+ v[i];
        
        }
        return 0;
    }
};