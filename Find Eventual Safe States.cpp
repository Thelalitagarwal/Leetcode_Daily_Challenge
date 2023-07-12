/*
Link to the " Find Eventual Safe States " Problem ==>> https://leetcode.com/problems/find-eventual-safe-states/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/7iRQGtz3qn8

*/

class Solution {
public:
    map<int, int> safe;
    vector<int> res;
    
    bool dfs(int node, vector<vector<int>>& graph) {
        
        if (safe.find(node) != safe.end())
            return safe[node];
        
        safe[node] = 0;
        
        for (auto neighbor : graph[node]) {
            if (!dfs(neighbor, graph)) {
                return false;
            }
        }
        
        safe[node] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        for (int i = 0; i < graph.size(); i++) {
            
            if (dfs(i, graph)) {
                res.push_back(i);
            }
        }
        
    
        return res;
    }
};