/*
Link to the "Search a 2D Matrix" Problem ==>> https://leetcode.com/problems/search-a-2d-matrix/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/mVv4IpBHpMo

*/

// 2 Approaches are attached in this please check wisely

// 1st Method
/*
class Solution {
public:    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int r = m - 1;
        int c = 0;
        while (r>=0 && c<n){
            if (mat[r][c] == target) return true;
            else if (mat[r][c] < target) c++;
            else r--;
        }
        return false;
    }
};

*/
// 2 Method


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = (row*col)-1;

        while(low<=high){

            int mid = high+(low-high)/2;

            if(matrix[mid/col][mid%col]==target)
                return true;

            else if(matrix[mid/col][mid%col]<target)
                low = mid+1;
            else
                high = mid-1;
        }

        return false;
    }
};


