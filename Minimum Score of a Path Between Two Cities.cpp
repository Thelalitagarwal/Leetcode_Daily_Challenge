/*
Link to the " Minimum Score of a Path Between Two Cities " Problem ==>>  https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/rPhMZsnnRsA

*/

class Solution {
public:
    vector<bool> vis;

    void dfs(vector<vector<pair<int, int> > > &adj, int node, int &mn){

        if(vis[node]) 
            return;
        vis[node] = true;
        for(auto & [v, dist] : adj[node]){
            mn = min(mn, dist);
            dfs(adj, v, mn);
        }
    }


    int minScore(int n, vector<vector<int>>& roads){

        vector<vector<pair<int, int> > > adj(n + 1);
        vis = vector<bool> (n + 1, 0);
        for(auto & edge : roads){
            auto [u, v, dist] = tie(edge[0], edge[1], edge[2]);
            adj[u].emplace_back(v, dist);
            adj[v].emplace_back(u, dist);
        }
        int ans = 1e5;
        dfs(adj, 1, ans);
        return ans;
    }
};