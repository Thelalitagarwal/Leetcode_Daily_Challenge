/*
Link to the " Count Negative Numbers in a Sorted Matrix " Problem ==>> https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/QqU24e6Es60

*/

class Solution {
public:
    int binsearch(vector<vector<int>>& grid,int r, int si, int ei){
        if(si>ei)
            return 0;
        int mid = ei - (ei-si)/2;
        if(grid[r][mid]<0)
            return (ei-mid+1)+binsearch(grid,r,si,mid-1);
        return binsearch(grid,r,mid+1,ei);
    }

    int countNegatives(vector<vector<int>>& grid) {

        int count=0;
        for(int i=0; i<grid.size(); i++){
            count+=binsearch(grid,i,0,grid[i].size()-1);
        }
        return count;
    }
};