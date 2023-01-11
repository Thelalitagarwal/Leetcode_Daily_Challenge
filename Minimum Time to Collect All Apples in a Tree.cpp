/*
Link to the "Minimum Time to Collect All Apples in a Tree" Problem ==>>  https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/ypaeip_tuDQ 

*/

class Solution {
public:
    vector<vector<int>> graph;

    int dfs(vector<bool>& hasApple,int node,int d,int prev){
        int result=0;
        int temp;
        for(int &i:graph[node]){
            if(i!=prev){
                    temp=dfs(hasApple,i,d+1,node);
                    if(temp){
                        result+=temp-d;
                    }
                }
        }
        
        if(result || hasApple[node]){
            return result+d;
        }
        return 0;
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){

        graph.resize(n);
        for(vector<int> &e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return dfs(hasApple,0,0,-1)*2;
    }
};