/*
Link to the "Remove Duplicate Letters" Problem ==>> https://leetcode.com/problems/remove-duplicate-letters/?envType=daily-question&envId=2023-09-26 
   
Link to the complete Explaination Video ==>> https://youtu.be/0p40TgDt2a0

*/

class Solution {
public:
    string removeDuplicateLetters(string s) {

        stack<char> charStack;

        vector<int> count(26, 0); 

        vector<bool> inStack(26, false);

        for (char c : s) {
            count[c - 'a']++;  
        }


        for (char c : s) {

            count[c - 'a']--; 

            if (inStack[c - 'a']){
                    continue; 
            }

            while (!charStack.empty() && c < charStack.top() && count[charStack.top() - 'a'] > 0) {
                    inStack[charStack.top() - 'a'] = false;
                    charStack.pop();
            }
            charStack.push(c);
            inStack[c - 'a'] = true;
        }
        string result = "";
        
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }
        return result;
   }
};