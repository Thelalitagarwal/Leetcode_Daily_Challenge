class Solution {
public:
    string reverseWords(string s) {
        for(int end = 0, start = 0; end <= s.size(); end++){
            if(s[end] == ' ' or s[end] == '\0'){
                reverse(s.begin()+start, s.begin()+end);
                start = end+1;
            }
        }
        return s;
    }
};