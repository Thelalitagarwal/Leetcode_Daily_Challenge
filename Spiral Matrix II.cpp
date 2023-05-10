/*
Link to the " Spiral Matrix II " Problem ==>> https://leetcode.com/problems/spiral-matrix-ii/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/YRbxaykAh8Is

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n,vector<int>(n,0));
        int startingRow=0;
        int endingRow=n-1;
        int startingCol=0;
        int endingCol=n-1;
        int total=n*n;
        int cnt=1;
        while(cnt<=total)
        {
            for(int i=startingCol;i<=endingCol&&cnt<=total;i++)
            {
                ans[startingRow][i]=cnt;
                cnt++;
            }
            startingRow++;
            for(int i=startingRow;i<=endingRow&&cnt<=total;i++)
            {
                ans[i][endingCol]=cnt;
                cnt++;
            }
            endingCol--;
            for(int i=endingCol;i>=startingCol&&cnt<=total;i--)
            {
                ans[endingRow][i]=cnt;
                cnt++;
            }
            endingRow--;
            for(int i=endingRow;i>=startingRow&&cnt<=total;i--)
            {
                ans[i][startingCol]=cnt;
                cnt++;
            }
            startingCol++;
        }
        return ans;
    }
};