/*
Link to the "Number of Nodes in the Sub-Tree With the Same Label" Problem ==>>  https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/q0DqaFI75JA 

*/

//  DFS APPROACH

class Solution {
public:
    vector<int>ans;

    vector<vector<int>>graph;
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {


        ans.resize(n,0);

        graph.resize(n,vector<int>{});
        
        for(auto it:edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        dfs(0, -1, labels);
        return ans;
    }
    
    
    vector<int> dfs(int s, int par, string &labels) {
		
        vector<int>res(26,0);

        res[labels[s]-'a']++;

        for(int it:graph[s]) {
            
            if(it == par)
                continue;
            
            vector<int> f = dfs(it, s, labels);

            for(int i=0; i<26; ++i) {
                res[i]+=f[i];
            }
        }

        ans[s] = res[labels[s]-'a'];
        
        return res;
    }
};


//  BFS APPROACH


/*


class Solution {
public:
    void addVectors(vector<int>& a, vector<int>& b){
        for(int i=0; i<a.size(); i++){
            a[i] = a[i] + b[i];
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        if(n==1){
            return {labels[0]-'a'};
        }
        vector<vector<int>> countMap(n, vector<int>(26, 0));
        vector<unordered_set<int>> adjacentNodes(n, unordered_set<int>());
        vector<int> result;
        for(int i=0; i<edges.size(); i++){
            adjacentNodes[edges[i][0]].insert(edges[i][1]);
            adjacentNodes[edges[i][1]].insert(edges[i][0]);
        }
        queue<int> q;
        countMap[0][labels[0]-'a']++;
        for(int i=1; i<n; i++){
            if(adjacentNodes[i].size()==1){
                q.push(i);
            }
            countMap[i][labels[i]-'a']++;
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int node: adjacentNodes[top]){
                adjacentNodes[node].erase(top);
                addVectors(countMap[node], countMap[top]);
                if(node!=0 && adjacentNodes[node].size()==1){
                    q.push(node);
                } 
            }
        }
        for(int i=0; i<n; i++){
            result.push_back(countMap[i][labels[i]-'a']);
        }
        return result;
    }
};

*/