/*
Link to the "Evaluate Reverse Polish Notation" Problem ==>>  https://leetcode.com/problems/keys-and-rooms/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/aH3Og3dKpCM 

*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        int n=rooms.size();
        vector<int> visited(n,0);
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            for (int k : rooms[current]){
                if(visited[k]==0){
                    q.push(k);
                    visited[k]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                return false;
            }
        }
        return true;
    }
};