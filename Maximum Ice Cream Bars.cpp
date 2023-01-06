class Solution {
public:
    int maxIceCream(vector<int>& A, int coins) {
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); ++i)
            if ((coins -= A[i]) < 0)
                return i;
        return A.size();
    }
};