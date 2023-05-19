/*
Link to the " Is Graph Bipartite? " Problem ==>> https://leetcode.com/problems/is-graph-bipartite/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/RrZuqyCj1hg

*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int v[graph.size()];
        memset(v,-1,sizeof(v));
        for(int i=0; i<graph.size(); i++){
            if(v[i]==-1){
                v[i]=0;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int ind=q.front();
                    q.pop();
                    for(auto it: graph[ind]){
                        if(v[it]==-1){
                            v[it]=!v[ind];
                            q.push(it);
                        }
                        else if(v[it]==v[ind]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};