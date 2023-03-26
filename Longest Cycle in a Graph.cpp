/*
Link to the " Longest Cycle in a Graph " Problem ==>>  https://leetcode.com/problems/longest-cycle-in-a-graph/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/JmIb_Xb4qoM

*/

class Solution {
public:
    void topo(int i, vector<vector<int>>& adj, vector<int> &vis, stack<int> &st){
	    vis[i]=1;
	    for(auto x: adj[i])
	        if(vis[x]==0)
	            topo(x,adj,vis,st);
	    st.push(i);
	}

	void dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &ans){
	    vis[i]=1;
        ans.push_back(i);
	    for(auto x: adj[i])
	        if(vis[x]==0)
	            dfs(x, adj, vis, ans);
	}

    int kosaraju(int n, vector<vector<int>>& adj) {
        int ans=0;
        stack<int> st;
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++) {
            if(vis[i]==0) {
                topo(i, adj, vis, st);
            }
        }
        vector<int> adjRev[n];
        for(int i=0;i<n;i++) {
            vis[i]=0;
            for(auto x: adj[i]) {
                adjRev[x].push_back(i);
            }
        }
        while(st.size()) {
            int node=st.top(); 
            st.pop();
            if(vis[node]==0) {
                vector<int> temp;
                dfs(node, adjRev, vis, temp);           
                if(ans<temp.size()) 
                    ans=temp.size();
            }
        }
        return ans;
    }

    int longestCycle(vector<int>& a) {

        int i, n=a.size();
        vector<vector<int>>adj(n);
        for(i=0;i<n;i++) {
            if(a[i]>=0)
             adj[i].push_back(a[i]);
        }
        int cyclesize=kosaraju(n, adj);
        if(cyclesize>1){
            return cyclesize;
        }
        return -1;
    }
};