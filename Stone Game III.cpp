/*
Link to the " Stone Game III " Problem ==>> https://leetcode.com/problems/stone-game-iii/ 
   
Link to the complete Explaination Video ==>>https://youtu.be/5zfsDxERaik

*/


class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        vector<int> bestScore(stoneValue.size(), 0);

        for(int i = bestScore.size() - 1; i >= 0; i--){

            int take = 0;

            int best = INT_MIN;

            for(int j = 0; j < 3 && i + j < stoneValue.size(); j++){
                
                take += stoneValue[i + j];
                int oppo = (i + j + 1 < stoneValue.size()) ? bestScore[i + j + 1] : 0;
                best = max(best, take - oppo);
            }

            bestScore[i] = best;
            
        }

        return (bestScore[0] > 0) ? "Alice" : (bestScore[0] == 0) ? "Tie" : "Bob";
    }
};