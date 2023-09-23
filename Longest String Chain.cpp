/*
Link to the "Is Subsequence" Problem ==>> https://leetcode.com/problems/longest-string-chain/?envType=daily-question&envId=2023-09-23 
   
Link to the complete Explaination Video ==>> https://youtu.be/eS3a5sOMyog

*/

class Solution {
public:
    static bool cmp(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), cmp);

        unordered_map<string, int> ump;

        int ans = 0;

        for (string w : words) {
            int longest=0;

            for (int i = 0; i < w.length(); i++) {
                string sub = w;
                sub.erase(i, 1);
                longest = max(longest,ump[sub]+1);
            }

            ump[w] = longest;

            ans = max(ans,longest);
        }
        return ans;
    }
};