class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> u;
        map<int,int> m;
        int n=matches.size();
        for(int i=0;i<n;i++){
            u.insert(matches[i][1]);
            u.insert(matches[i][0]);
            m[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        n=u.size();
        
        for(auto i=u.begin();i!=u.end();i++){
            if(!m[*i])    ans[0].push_back(*i);
            else if(m[*i]==1)   ans[1].push_back(*i);
        }
        
        sort(ans[1].begin(),ans[1].end());
        sort(ans[0].begin(),ans[0].end());
        
        return ans;
    }
};