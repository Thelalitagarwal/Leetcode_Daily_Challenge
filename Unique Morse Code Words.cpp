class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> t = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        // insert to set so that we can find unique solutions
        set<string> s;

        for(int i = 0; i < words.size();i++){
            string tt = words[i]; // Present word
            string temp = ""; // to store coded word from tt

            for(int j= 0 ;j < tt.length(); j++){
                int e = tt[j] - 'a'; // we get the particular index
                temp += t[e];
            }
            s.insert(temp); // insert all codes
        }
        return s.size(); // we get unquie number
    }
};