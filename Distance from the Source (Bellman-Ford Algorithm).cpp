#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    void bfs(int v,vector<vector<int>> adj,int s,vector<int> &visited){
        queue<int> a;
        a.push(s);
        while(!a.empty()){
            int node=a.front();
            a.pop();
            for(int i=0;i<adj.size();i++){
                if(adj[i][0]==node){
                    if(visited[adj[i][1]]>visited[adj[i][0]]+adj[i][2]){
                        visited[adj[i][1]]=visited[adj[i][0]]+adj[i][2];
                        a.push(adj[i][1]);
                    }
                }
            }
        }
    }
    
    vector <int> bellman_ford(int v, vector<vector<int>> adj, int s) {
        vector<int> visited(v,100000000);
        visited[s]=0;
        bfs(v,adj,s,visited);
        return visited;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

