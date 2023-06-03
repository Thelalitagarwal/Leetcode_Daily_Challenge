/*
Link to the " Time Needed to Inform All Employees " Problem ==>> https://leetcode.com/problems/time-needed-to-inform-all-employees/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/otmkpRqEZKg

*/

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<int> t;
        t.push(headID);
        int ans = informTime[headID];
        vector<vector<int>> graph (n);
        for (int i=0; i<manager.size(); i++){
            if ( manager[i]!= -1){
                graph[manager[i]].push_back(i);
            }
        }
        while(!t.empty()){
            int curr = t.front();
            t.pop();
            for (int i=0; i<graph[curr].size(); i++){
                    int next = graph[curr][i];
                    t.push(next);
                    informTime[next] = informTime[next] + informTime[curr];       
                    ans = max(ans, informTime[next]);
            }
        }
        return ans;
    }
};