/*
Link to the "Cheapest Flights Within K Stops" Problem ==>>  https://leetcode.com/problems/cheapest-flights-within-k-stops/4 
   
Link to the complete Explaination Video ==>> https://youtu.be/Xp0FktTrbWk

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int st, int en, int k) {
        vector<int> price(n, 1e9);
        vector<vector<pair<int, int>>> adj(n);
        queue<pair<int, pair<int, int>>> q;
        for (vector<int>& v : edges) 
            adj[v[0]].push_back({v[1], v[2]});
        q.push({st, {0, 0}});
        price[st] = 0;
        while (!q.empty()) {
            int cur = q.front().first;
            int curprice = q.front().second.first;
            int moves = q.front().second.second;
            q.pop();
            if (moves > k)
                continue;
            for (pair<int, int>& p : adj[cur]) {
                if (price[p.first] <= curprice + p.second)
                    continue;
                q.push({p.first, {curprice + p.second, moves + 1}});
                price[p.first] = curprice + p.second;
            }
        }
        return price[en] == 1e9 ? -1 : price[en];
    }
};