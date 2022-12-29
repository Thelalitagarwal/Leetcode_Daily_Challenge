class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& A) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int N = A.size();
        long time = 0;
        int i = 0;
        for (int i = 0; i < N; ++i){
            A[i].push_back(i);
        }
        sort(begin(A), end(A));
        vector<int> ans;
        while (i < N || pq.size()){
            if (pq.empty()) {
                time = max(time, (long)A[i][0]);
            }
            while (i < N && time >= A[i][0]){
                pq.push({A[i][1],A[i][2]});
                ++i;
            }
            pair<long,long> s= pq.top();
            pq.pop();
            time += s.first;
            ans.push_back(s.second);
        }
        return ans;
    }
};