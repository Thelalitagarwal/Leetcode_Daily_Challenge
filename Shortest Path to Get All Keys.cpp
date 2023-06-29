/*
Link to the " Shortest Path to Get All Keys " Problem ==>> https://leetcode.com/problems/shortest-path-to-get-all-keys/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/8JLFMlcxHyc

*/


class Solution {
public:
    bool checker(int x, int y, int n, int m)
    {
        if(x >= 0 && x<n && y>=0 && y<m) return true;
        return false;
    }

    int shortestPathAllKeys(vector<string>& grid) {

        int nkeys=0, inix=0, iniy=0;

        for(int i=0; i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '@'){
                    inix = i;
                    iniy = j;
                }
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'z') 
                    nkeys++;
            }
        }

        int mask = 1<<(nkeys);  // 100 
        int orig = 1<<(nkeys+1); // 1000-1 === (8-1==7)

        vector<vector<vector<bool>>> vis(orig, vector<vector<bool>> (grid.size(), vector<bool> (grid[0].size(), false)));

        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};

        queue<pair<pair<int,int>,pair<int,int>>> q;

        q.push(make_pair(make_pair(inix, iniy),make_pair(0,mask)));

        while(!q.empty())
        {
            pair<pair<int,int>,pair<int,int>> p = q.front();
            q.pop();

            vis[p.second.second][p.first.first][p.first.second] = true;

            if(p.second.second == (orig-1) )
                return p.second.first;

            for(int i=0;i<4; i++)
            {
                int xx = p.first.first + dx[i];
                int yy = p.first.second + dy[i];
                if(checker(xx,yy,grid.size(),grid[0].size()) && grid[xx][yy] != '#' && !vis[p.second.second][xx][yy]){
                    if(grid[xx][yy] >= 'a' && grid[xx][yy] <= 'z'){
                        int l = grid[xx][yy]-'a';
                        if((p.second.second & (1<<l)) == 0)
                        {
                            q.push(make_pair(make_pair(xx,yy),make_pair(p.second.first+1,p.second.second | (1<<l))));
                            vis[p.second.second | (1<<l)][xx][yy] = true;
                        }
                        else
                        {
                            q.push(make_pair(make_pair(xx,yy),make_pair(p.second.first+1,p.second.second )));
                            vis[p.second.second][xx][yy] = true;
                        }

                    }
                    else if(grid[xx][yy] >= 'A' && grid[xx][yy] <= 'Z')
                    {
                        int l = grid[xx][yy]+32 -'a';
                        if((p.second.second & (1<<l)) != 0)
                        {
                            q.push(make_pair(make_pair(xx,yy),make_pair(p.second.first+1,p.second.second)));
                            vis[p.second.second][xx][yy] = true;
                        } 
                    }
                    else
                    {
                        q.push(make_pair(make_pair(xx,yy),make_pair(p.second.first+1,p.second.second)));
                        vis[p.second.second][xx][yy]=true;
                    }
                    
                }
            }
        }
        return -1;
    }
};