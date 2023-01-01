/*
Link to the "Word Pattern" Problem ==>>  https://leetcode.com/problems/word-pattern/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/VRtmyXrGG0Y 

*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        int ptr1 = 0, ptr2 = 0;
        for(int i = 0; i < pattern.size(); ++i) {
            string substr;
            if(i != pattern.size() - 1) {
                ptr2 = s.find(' ', ptr1);
                substr =s.substr(ptr1, ptr2 - ptr1);
            } 
            else{
                substr = s.substr(ptr1, s.size() - ptr1);
            }
            if(substr == "") 
                return false;
            
            if(not m1.count(pattern[i])) 
                m1[pattern[i]] = substr;  
            
            if(not m2.count(substr)) 
                m2[substr] = pattern[i];
            
            if(m1[pattern[i]] != substr || m2[substr] != pattern[i]) 
                return false;
            
            ptr1 = ptr2 + 1;
        }
        return true;
    }
};