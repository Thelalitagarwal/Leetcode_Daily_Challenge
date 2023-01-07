class Solution {
public:
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int max = gas[n-1] - cost[n-1];
        int total = max;
        int ans = n-1;
        
        for (int i = n-2; i >= 0; i--) {
            total += gas[i] - cost[i];
            if (total > max) {
                ans = i;
                max = total;
            }
        }
        return total >= 0 ? ans : -1;
    }
};