/*
Link to the " Detonate the Maximum Bombs " Problem ==>> https://leetcode.com/problems/detonate-the-maximum-bombs/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/ubg1qh_4r3E

*/


class Solution {
public:
        int bfs(vector<vector<int>>&bombs,int source){

            int n = bombs.size();
            vector<bool>vis(n,false);
            queue<pair<int,pair<int,int>>>q;
            q.push({bombs[source][2],{bombs[source][0],bombs[source][1]}});
            vis[source] = true;
            int count = 1;
            while(!q.empty()){
                {
                    long long int a = q.front().second.first,b = q.front().second.second;
                    long long int r = q.front().first;
                    q.pop();
                    for(int i=0;i<n;i++){
                        if(!vis[i]){
                            long long int c = bombs[i][0],d = bombs[i][1],e = abs(a-c),f = abs(d-b);
                            if(e*e+f*f<=r*r){

                                count++;
                                vis[i] = true;
                                
                                q.push({bombs[i][2],{bombs[i][0],bombs[i][1]}});
                            }
                        }
                    }
                }
            }
            return count;
        }


    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,bfs(bombs,i));
        }
        return maxi;
    }
};