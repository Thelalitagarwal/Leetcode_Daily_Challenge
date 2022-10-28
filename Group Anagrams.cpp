class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> ans;
       unordered_map<string, vector<string>> mp;
        for(int i = 0 ; i < strs.size() ; i++)
        {
            string s = strs[i];
            sort(strs[i].begin(),strs[i].end());   
            mp[strs[i]].push_back(s);
        }
        for(auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};