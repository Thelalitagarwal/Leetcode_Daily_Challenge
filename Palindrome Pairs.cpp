class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) 
            if (s[l++] != s[r--])
                return false;

        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> pool;
        set<int> mySet;

        for (int i = 0; i < words.size(); ++i) {
            pool[words[i]] = i;
            mySet.insert(words[i].size());
        }
        
        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            int len = s.size();
            reverse(s.begin(), s.end());
        
            if (pool.count(s) && pool[s] != i) {
                res.push_back({i, pool[s]});
            }
        
            auto a = mySet.find(len);
            for (auto it = mySet.begin(); it != a; ++it) {
                int d = *it;
                if (isPalindrome(s, 0, len - d - 1) && pool.count(s.substr(len - d))) {
                    res.push_back({i, pool[s.substr(len - d)]});
                }
                if (isPalindrome(s, d, len - 1) && pool.count(s.substr(0, d))) {
                    res.push_back({pool[s.substr(0, d)], i});
                }
            }
        }
        
        return res;
    }
};