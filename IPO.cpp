/*
Link to the "IPO" Problem ==>>  https://leetcode.com/problems/ipo/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/m4mwEPsCJvg

*/

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++)
            projects[i] = {profits[i], capital[i]};
        sort(projects.begin(), projects.end(), cmp);
        int i = 0;
        priority_queue<int> PQ;
        while (k--) {
            while (i < n && projects[i].second <= w) {
                PQ.push(projects[i].first);
                i++;
            }
            if (!PQ.empty()) {
                w += PQ.top();
                PQ.pop();
            }
        }
        return w;
    }
};