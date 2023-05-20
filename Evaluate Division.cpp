/*
Link to the " Evaluate Division " Problem ==>> https://leetcode.com/problems/evaluate-division/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/zNCSHKj5hOE

*/


class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;
     double DFS(string src, string dst, unordered_set<string> &visited){

        if(graph.find(src) == graph.end())
            return -1.0;
        
        if(src == dst) 
            return 1;
        
        visited.insert(src);

        for(auto node:graph[src]){

            if(visited.find(node.first) != visited.end()) 
                continue;
            
            double res = DFS(node.first, dst, visited);
            if(res != -1){
                return res*node.second;
            }

        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n = equations.size();

        for(int i=0;i<n;i++){

            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b,val});
            graph[b].push_back({a,(1/val)});
        }

        vector<double> result;
        for(auto query:queries){
            unordered_set<string> visited;
            result.push_back(DFS(query[0],query[1],visited));
        }
        return result;
    }
   
};