class Solution 
{
public:
    bool possibleBipartition(int N, vector<vector<int>> &edges) {

        vector<vector<int>> adj(N + 1);
        vector<int> color(N + 1, 0);
        vector<bool> explored(N + 1, false);
        for (auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q; 
        for (int i = 1; i <= N; ++i){
            if (!explored[i]){
                color[i] = 1;
                q.push(i);
                while (!q.empty()){
                    int u = q.front();
                    q.pop(); 
                    if (explored[u]){
                        continue;
                    }
                    explored[u] = true;
                    for (auto v: adj[u]){
                        if (color[v] == color[u]){
                            return false;
                        }
                        if (color[u] == 1){
                            color[v] = 2;
                        }
                        else{
                            color[v] = 1;
                        }
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};