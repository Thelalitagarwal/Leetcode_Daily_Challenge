class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i=0, ans=0;
        priority_queue<int> pq;
        while(startFuel < target) {
            while(i < stations.size() && stations[i][0] <= startFuel) {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.size()==0) return -1;
            startFuel += pq.top(); pq.pop();
            ans++;
        }
        return ans;
    }
};