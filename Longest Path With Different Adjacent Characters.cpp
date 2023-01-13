/*
Link to the "Longest Path With Different Adjacent Characters" Problem ==>>  https://leetcode.com/problems/longest-path-with-different-adjacent-characters/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/ZJqtLdItPyk

*/

// DFS APPROACH C++


class Solution {
public:
        int longestPath(vector<int>& parent, string s) {
        int n = s.size(), res = 0;
        vector<vector<int>> children(n, vector<int>());
        for (int i = 1; i < n; ++i)
            children[parent[i]].push_back(i);
        dfs(children, s, res, 0);
        return res;
    }

    int dfs(vector<vector<int>>& children, string& s, int& res, int i) {
        int big1 = 0, big2 = 0;
        for (int& j : children[i]) {
            int cur = dfs(children, s, res, j);
            if (s[i] == s[j]) 
                continue;
            if (cur > big2) big2 = cur;
            if (big2 > big1) swap(big1, big2);
        }
        res = max(res, big1 + big2 + 1);
        return big1 + 1;
    }
};


/*

//BFS APPROACH C++

int find(int i, vector<bool>& vis, vector<vector<int>>& adj){
    vector<bool>v(vis.size(), false);
    v[i]=true;
    queue<int>q;
    q.push(i);
    int k;
    int l=0;
    while(!q.empty()){
        int j=q.front();
        if(q.size()==1)k=q.front();
        q.pop();
        for(int t=0; t<adj[j].size(); t++){
            if(!v[adj[j][t]])q.push(adj[j][t]);
            v[adj[j][t]]=true;
        }
    }
    q.push(k);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            int j=q.front();
            vis[j]=true;
            q.pop();
            for(int t=0; t<adj[j].size(); t++){
                if(!vis[adj[j][t]])q.push(adj[j][t]);
                vis[adj[j][t]]=true;
            }
        }
        l++;
    }
    return l;
}
int longestPath(vector<int>& parent, string s) {
    vector<vector<int>>adj(parent.size());
    unordered_set<int>st;
    for(int i=1; i<parent.size(); i++){
        if(s[parent[i]]!=s[i]){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
            st.insert(i);
            st.insert(parent[i]);
        }
    }
    if(st.size()==0)return 1;
    int n = adj.size();
    vector<bool>vis(n,false);
    int ans=0;
    for(auto &i: st){
        if(!vis[i]) {
            ans=max(ans, find(i, vis, adj));
        }
    }
    return ans;
}


//DFS APPROACH JAVA

class Solution {
public:
            int res;
    public int longestPath(int[] parent, String s) {
        res = 0;
        ArrayList<Integer>[] children = new ArrayList[parent.length];
        for (int i = 0; i < parent.length; i++)
            children[i] = new ArrayList<>();
        for (int i = 1; i < parent.length; i++)
            children[parent[i]].add(i);
        dfs(children, s, 0);
        return res;
    }

    private int dfs(ArrayList<Integer>[] children, String s, int i) {
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int j : children[i]) {
            int cur = dfs(children, s, j);
            if (s.charAt(j) != s.charAt(i))
                queue.offer(-cur);
        }
        int big1 = queue.isEmpty() ? 0 : -queue.poll();
        int big2 = queue.isEmpty() ? 0 : -queue.poll();
        res = Math.max(res, big1 + big2 + 1);
        return big1 + 1;
    }
};


// DFS APPROACH PYTHON

class Solution:
        def longestPath(self, parent, s):
        children = [[] for i in range(len(s))]
        for i,j in enumerate(parent):
            if j >= 0:
                children[j].append(i)
        
        res = [0]
        def dfs(i):
            candi = [0]
            for j in children[i]:
                cur = dfs(j)
                if s[i] != s[j]:
                    candi.append(cur)
                    
            candi = nlargest(2, candi)
            res[0] = max(res[0], sum(candi) + 1)
            return max(candi) + 1
        
        dfs(0)
        return res[0]
        

*/