/*
Link to the "Number of Good Paths" Problem ==>>  https://leetcode.com/problems/number-of-good-paths/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/Zoa7zEpBihI

*/

class Solution {
    vector<map<int, int>> mp;
    vector<vector<int>> graph;
    vector<int> flag;
    
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        mp.resize(n);
        graph.resize(n);
        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int ans = 0;
        flag.resize(n, 0);
        dfs(ans, 0, vals);   
        return ans+n;
    }
    void dfs(int &count, int u, vector<int>& vals) {
        flag[u] = 1;
        for (auto &v: graph[u]) {
            if (flag[v] == 1) 
                continue;
            int cnt = 0;
            dfs(cnt, v, vals);
            count += cnt;
            auto it = mp[v].lower_bound(vals[u]);
            mp[v].erase(mp[v].begin(), it);
            if (mp[u].size() < mp[v].size()) {
                swap(mp[u], mp[v]);    
            }   
            for (auto &it: mp[v]) {
                count += mp[u][it.first] * it.second;
                mp[u][it.first] += it.second;
            }
        }
        count += mp[u][vals[u]];
        ++mp[u][vals[u]];
    }
};