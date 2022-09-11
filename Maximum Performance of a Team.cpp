class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int MOD = 1e9 + 7;
        vector<pair<int, int>> candidates(n);
        for (int i = 0; i < n; i++) candidates[i] = { efficiency[i], speed[i] };
        sort(candidates.rbegin(), candidates.rend());
        long speedSum = 0, ans = 0;
        priority_queue <int, vector<int>, greater<int>> pq;
        for (auto& [e, s] : candidates) {
            pq.push(s);
            speedSum += s;
            if (pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }
            ans = max(ans, speedSum * e);
        }
        return ans % MOD;
    }
};