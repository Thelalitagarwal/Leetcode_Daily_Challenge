class Solution {
private:
    int effort[105][105];

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

public:
    int dijkstra(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        priority_queue<pair<int,pair<int, int>>> pq;

        pq.push({0, {0, 0}});

        effort[0][0] = 0;

        while (!pq.empty()) {

            auto current = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();

            int x = current.first;
            int y = current.second;
            if (cost > effort[x][y])
                continue;
            
            if (x == rows - 1 && y == cols - 1)
                return cost;

            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols)
                    continue;
                
                int new_effort =max(effort[x][y],abs(heights[x][y] - heights[new_x][new_y]));
                if (new_effort < effort[new_x][new_y]) {
                    effort[new_x][new_y] = new_effort;
                    pq.push({-new_effort, {new_x, new_y}});
                }
            }
        }
        return effort[rows - 1][cols - 1];
    }


    int minimumEffortPath(vector<vector<int>>& heights) {

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                effort[i][j] = INT_MAX;
            }
        }
        return dijkstra(heights);
    }
};