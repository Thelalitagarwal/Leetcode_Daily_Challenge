int f[105][105][30][105];

class Solution {
     string str;
    int dfs(int idx, int k, int last, int concat) {
        if (k < 0) return 9999999;
        if (idx == str.size()) return 0;
        
        int& val = f[idx][k][last][concat];
        if (val != -1) return val;
        
        int answer = 9999999;
	    // delete
        answer = min(answer, dfs(idx + 1, k - 1, last, concat));
        // concat
        if (last == str[idx] - 'a') {
            int fac = (concat == 1 || concat == 9 || concat == 99) ? 1 : 0;
            answer = min(answer, fac + dfs(idx + 1, k, last, concat + 1));
        } else {
            answer = min(answer, 1 + dfs(idx + 1, k, str[idx] - 'a', 1));
        }
        return val = answer;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        int N = s.size();
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                for (int k = 0; k <= 26; k++) {
                    for (int m = 0; m <= N; m++) {
                        f[i][j][k][m] = -1;
                    }
                }
            }
        }
        return dfs(0, k, 26, 0);
    }
   
};