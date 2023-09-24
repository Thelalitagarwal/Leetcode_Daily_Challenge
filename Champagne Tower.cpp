/*
Link to the "Champagne Tower" Problem ==>> https://leetcode.com/problems/champagne-tower/description/?envType=daily-question&envId=2023-09-24 
   
Link to the complete Explaination Video ==>> https://youtu.be/OT8L13mxv9E

*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<double> currRow(1, poured);

        for(int i=0; i<=query_row; i++){

            vector<double> nextRow(i+2, 0);

            for(int j=0; j<=i; j++){

                if(currRow[j]>=1){

                    nextRow[j] += (currRow[j]-1)/2.0;
                    nextRow[j+1] += (currRow[j]-1)/2.0;
                    currRow[j] = 1;
                    
                }
            }
            if(i!=query_row) 
                currRow = nextRow;
        }
        return currRow[query_glass];
    }
};