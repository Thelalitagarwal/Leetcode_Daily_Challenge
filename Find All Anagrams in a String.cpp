/*
Link to the "Find All Anagrams in a String" Problem ==>>  https://leetcode.com/problems/find-all-anagrams-in-a-string/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/K8SNpv-aW9s

*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        int window = p.size();
        int len = s.size();
        if(len < window){
            return ans;
        }
        int left = 0,right = 0;
        while(right < window){
            phash[p[right] - 'a'] += 1;
            hash[s[right] - 'a'] += 1;
            right++;
        }
        right -=1;
        while(right < len){
            if(phash == hash){
                ans.push_back(left);
            }
            right+=1;
            if(right != len){
                hash[s[right] - 'a'] += 1;
            }
            hash[s[left] - 'a'] -=1 ;
            left++;
        }
        return ans;
    }
};