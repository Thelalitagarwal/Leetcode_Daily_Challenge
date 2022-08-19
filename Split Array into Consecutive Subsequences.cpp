class Solution {
public:
    bool isPossible(vector<int>& nums) {
        multiset<int> l1, l2, l3;
        for (int i : nums) {
            if (l1.find(i - 1) != l1.end()) {
                l1.erase(l1.find(i - 1)), l2.insert(i);
            } else if (l2.find(i - 1) != l2.end()) {
                l2.erase(l2.find(i - 1)), l3.insert(i);
            } else if (l3.find(i - 1) != l3.end()) {
                l3.erase(l3.find(i - 1)), l3.insert(i);
            } else {
                l1.insert(i);
            }
        }
        return l1.empty() && l2.empty();
    }
};