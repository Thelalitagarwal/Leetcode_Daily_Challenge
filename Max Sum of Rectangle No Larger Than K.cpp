class Solution {
    public:
        int maxSumSubmatrix(vector<vector<int>>& m, int k) {
            int res = INT_MIN, rows = m.size(), cols = m[0].size();
            for (int l = 0; l < cols; ++l) {
                vector<int> sums(rows);
                for (int r = l; r < cols; ++r) {
                    for (int i = 0; i < rows; ++i){
                        sums[i] += m[i][r];
                    }
                    set<int> s = {0};
                    int maxisum = 0;
                    for (int sum : sums) {
                        maxisum += sum;
                        auto it = s.lower_bound(maxisum - k);
                        if (it != end(s))
                            res = max(res, maxisum - *it);
                        s.insert(maxisum);
                    }
                }
            }
            return res;
        }  
};
