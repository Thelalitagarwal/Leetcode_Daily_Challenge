/*
Link to the " Reorder Routes to Make All Paths Lead to the City Zero " Problem ==>>  https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/9HqTe9akgNk

*/

#define OUTGOING 1
#define INCOMING 0
#define NOT_VISITED 0
#define VISITED 1

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections){
        vector<vector<pair<int, bool>>> adj(n);
        for(auto i: connections){
           adj[i[0]].push_back(make_pair(i[1],OUTGOING));
           adj[i[1]].push_back(make_pair(i[0],INCOMING));
        }

        vector<bool> visited(n, NOT_VISITED);  
        int count=0;
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto i:adj[u]){
                if(visited[i.first] == NOT_VISITED){
                    if(i.second == OUTGOING)
                        count++;
                    q.push(i.first);
                    visited[i.first] = VISITED;
                }
            }
        }
        return count;
    }
};