class Solution {
public:
       int totalFruit(vector<int> &tree) {
        unordered_map<int, int> count;
        int i, j,ans=INT_MIN;
        for (i = 0, j = 0; j < tree.size(); ++j) {
            count[tree[j]]++;
            while(count.size() > 2) {
                if (--count[tree[i]] == 0)count.erase(tree[i]);
                i++;
            }
            ans=max(ans,(j-i+1));
        }
        return ans;
    }
};