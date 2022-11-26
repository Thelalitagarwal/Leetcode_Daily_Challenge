class Solution {
public:    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
	    int n = startTime.size();
        int dp[n];
        vector<pair<int,pair<int,int>>> y(n);
        for(int i = 0; i < n; i++){
            y[i].first = endTime[i];
            y[i].second.first = startTime[i];
            y[i].second.second = profit[i];
        }
	    sort(y.begin(), y.end());
        for (int i = 0; i < n; i++) {
            if (i==0){
                dp[i] = y[i].second.second;
                continue;
            }
            int f = 0;
            for (int j = i - 1; j >= 0; j--){
                if (y[j].first <= y[i].second.first){
                    f = dp[j];
                    break;
                }
            }
            dp[i] = max(dp[i-1],f+y[i].second.second);
	    }
	    return dp[n - 1];
    }
};