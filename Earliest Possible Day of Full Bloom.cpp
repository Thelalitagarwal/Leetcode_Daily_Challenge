class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> times(n);
        for (int i = 0; i < n; i++) {
            times[i].first = -growTime[i];
            times[i].second = plantTime[i];
        }
        sort(times.begin(),times.end());
        int total = 0;
        int current = 0;
        for (int i = 0; i < n; i++) {
            total = max(total,current+times[i].second-times[i].first);
            current += times[i].second;
        }
        return total;
    }
};