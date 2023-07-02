/*
Link to the " Maximum Number of Achievable Transfer Requests " Problem ==>> https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/e4nSuMiG3sc

*/

class Solution {
    bool countTotalBalancedBuildings(vector<int> &buildings) {
        for (auto build : buildings) {
            if (build != 0) 
                return false;
        }
        return true;
    }

    void calculatePossibleRequests(int n,int &possibleReqs,int reqCount,vector<vector<int>> &requests,vector<int> &buildings){
        
        if (countTotalBalancedBuildings(buildings))
            possibleReqs = max(possibleReqs, reqCount);
        if (n == requests.size())
            return;
        int buildLeaving = requests[n][0], buildEntering = requests[n][1];
        buildings[buildLeaving] ==buildings[buildLeaving]--;
        buildings[buildEntering] ==buildings[buildEntering]++;
        calculatePossibleRequests(n + 1, possibleReqs, reqCount + 1, requests, buildings);
        buildings[buildLeaving] +=1; 
        buildings[buildEntering] -=1;
        calculatePossibleRequests(n + 1, possibleReqs, reqCount, requests, buildings);
    }

public:
    int maximumRequests(int n, vector<vector<int>>& requests) {

        int possibleReqs = 0;
        vector<int> buildings(n, 0);
        calculatePossibleRequests(0, possibleReqs, 0, requests, buildings);
        return possibleReqs;
    }
};