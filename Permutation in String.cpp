/*
Link to the "Permutation in String" Problem ==>>  https://leetcode.com/problems/permutation-in-string/     
   
Link to the complete Explaination Video ==>> https://youtu.be/3zSSJvrXMG0

*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map< char, int >mp;
        for(auto it : s1){
           mp[it]++;
        }
        int count = mp.size();
        int i = 0, j = 0;
        int k = s1.size();
        while(j < s2.size()){
            if(mp.find(s2[j]) != mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]] == 0){
                    count--;
                }
            }
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
				if(count == 0){
					return true;  
				}
                if(mp.find(s2[i]) != mp.end()){
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1){
                        count++;
                    }    
                }
                i++;
                j++;
            }
        }
        return false;
    }
};