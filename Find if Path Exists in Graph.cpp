/*
Link to the "Find if Path Exists in Graph" Problem ==>>  https://leetcode.com/problems/find-if-path-exists-in-graph/description/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/siPPNnB-SeY 

*/


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        vector<int> visited(n, 0);
        q.push(start);
        visited[start] = 1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(top == end)
                return true;
            for(int i=0; i<graph[top].size(); i++){
                if(visited[graph[top][i]] == 0){
                    q.push(graph[top][i]);
                    visited[graph[top][i]] = 1;
                }
            }
        }
        return false;
    }
};