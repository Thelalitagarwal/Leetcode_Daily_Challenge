/*
Link to the "Naming a Company" Problem ==>>  https://leetcode.com/problems/naming-a-company/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/WPOkNEIkVPs

*/
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> t(ideas.begin(), ideas.end());
        unordered_map<char, unordered_map<char,int>> m;
        for (auto& str : t){
            string s = str;
            char prev = s[0];
            for (char c = 'a'; c <= 'z'; ++c){
                s[0] = c;
                if (t.find(s) == t.end())
                 ++m[c][prev];
            }
        }
        long long ans = 0;
        for (auto& str : t){
            string s = str;
            char prev = s[0];
            for (char c = 'a'; c <= 'z'; ++c){
                s[0] = c;
                if (t.find(s) == t.end())
                 ans += m[prev][c];
            }
        }
        return ans;
    }
};