/*
Link to the "Unique Paths III" Problem ==>>  https://leetcode.com/problems/unique-paths-iii/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/-dfUVNYPhtM 

*/

class Solution {
public:
    int ans=0;

    void func(vector<vector<int>> grid,int i,int j,int c){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return;
        }
        if(grid[i][j]==-1 || grid[i][j]==3){
            return;
        }
        if(grid[i][j]==2 && c==0){
            ans++;
            return;
        }
        if(grid[i][j]==2){
            return;
        }
        grid[i][j]=3;
        func(grid,i,j+1,c-1);
        func(grid,i+1,j,c-1);
        func(grid,i-1,j,c-1);
        func(grid,i,j-1,c-1);
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int x,y,c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
                if(grid[i][j]==0){
                    c++;
                }
            }
        }
        func(grid,x,y,c+1);
        return ans;
    }
};