/*
Link to the "Remove Colored Pieces if Both Neighbors are the Same Color" Problem ==>> https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
   
Link to the complete Explaination Video ==>> https://youtu.be/jaCf5jv_Z4I

*/

class Solution {
public:
    bool winnerOfGame(string colors) {
        int as = 0, bs = 0;
        for(int i = 1; i< colors.size()-1; i++){
            
            if(colors[i-1]== 'A' && colors[i] =='A' && colors[i+1] =='A'){
                as++;
            }
            if(colors[i-1] == 'B' && colors[i] =='B' && colors[i+1]== 'B'){
                bs++;
            }
        }
        return as > bs;
    }
};