/*
Link to the "Best Team With No Conflicts" Problem ==>>  https://leetcode.com/problems/best-team-with-no-conflicts/     
   
Link to the complete Explaination Video ==>> https://youtu.be/7ilwl-mcmQY

*/

class Solution {
public:
    int findMaxScore(vector<pair<int,int>>& ageScorePair){
        int n = ageScorePair.size();
        int answer = 0;
        vector<int> dp(n);
        for(int i = 0 ; i < n; i++){
            dp[i] = ageScorePair[i].second;
            answer = max(answer , dp[i]);
        }
        for(int i = 0 ; i < n;i++){
            for(int j = i-1 ; j >= 0;j--){
                if(ageScorePair[i].second >= ageScorePair[j].second ){
                    dp[i] = max(dp[i] , ageScorePair[i].second + dp[j]);
                }
            }
            answer = max(answer , dp[i]);
        }
        return answer;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        vector<pair<int,int>> ageScorePair;
        for(int i = 0 ; i < scores.size() ; i++){
            ageScorePair.push_back({ages[i],scores[i]});
        }
        sort(ageScorePair.begin() , ageScorePair.end());
        return findMaxScore(ageScorePair);
    }
};


    