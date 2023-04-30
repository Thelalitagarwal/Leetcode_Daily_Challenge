/*
Link to the " Remove Max Number of Edges to Keep Graph Fully Traversable " Problem ==>>  https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/NCsZGe6YpgU

*/

class Solution {
public:
    int notUsed = 0;
    int findParent(vector<int>&parent, int node)
    {
        if (parent[node] == node) return node;
        else return findParent(parent, parent[node]);
    }
    bool merge(vector<int>&parent, vector<int>&rank, int node1, int node2)
    {
        int parent1 = findParent(parent, node1);
        int parent2 = findParent(parent, node2);

        if (parent1 == parent2) 
            return false;
            
        else
        {
            if (rank[parent1] == rank[parent2]){
                parent[parent1] = parent2; 
                rank[parent2]++; 
            }
            else if (rank[parent1] < rank[parent2])
                parent[parent1] = parent2; 
            else
                parent[parent2] = parent1;
            return true;
        }
    }

    void solve(vector<vector<int>>&edges, vector<int>&parent, vector<int>&rank, int& componentCount, int currType){
        
        for (vector<int>&edge : edges){

            if (edge[0] != currType) 
                continue;      
              
            bool merged = merge(parent, rank, edge[1], edge[2]);
            if (!merged) notUsed++;
            else componentCount--;
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {

        int componentCount = n;

        vector<int>parent(n + 1);
        vector<int>rank(n + 1, 0);

        for (int i = 1; i <= n; i++) 
            parent[i] = i;

        solve(edges, parent, rank, componentCount, 3);
        
        vector<int>aliceParent = parent, aliceRank = rank;
        int aliceComponentCount = componentCount;
        solve(edges, aliceParent, aliceRank, aliceComponentCount, 1);
        if (aliceComponentCount != 1) 
            return -1;  
        vector<int>bobParent = parent, bobRank = rank; 
        int bobComponentCount = componentCount;
        solve(edges, bobParent, bobRank, bobComponentCount, 2);
        if (bobComponentCount != 1) 
            return -1; 
        return notUsed;
    }
};