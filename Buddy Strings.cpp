/*
Link to the " Buddy Strings " Problem ==>> https://leetcode.com/problems/buddy-strings/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/v2FWcP-QGqo

*/


class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if(s.size()!=goal.size()){
            return false;
        }

        unordered_map<char, int> mp;

        for(int i=0;i<s.length();i++) 
            mp[s[i]] = i;
        
        for(int i=0;i<goal.length();i++){

            if(mp.find(goal[i]) == mp.end()) 
                return false;
            
            if(mp[goal[i]] != i){
                swap(s[i], s[mp[goal[i]]]);
                if(s == goal) 
                    return true;
                
                swap(s[i], s[mp[goal[i]]]);
            }

        }
        return false;
    }
};