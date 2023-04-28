/*
Link to the " Similar String Groups " Problem ==>>  https://leetcode.com/problems/similar-string-groups/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/HQy8kq1KfdI

*/

class Solution {
public:
    vector<int> adj[305];
    int vis[305];
    
    void dfs(int v){
        vis[v]=1;
        for(auto u: adj[v]){
            if(!vis[u])
                dfs(u);
        }
    }
    
    bool similar(string s, string t){
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                c++;
                if(c>2)
                  return false;
            }
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {

        int n=strs.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(similar(strs[i],strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};