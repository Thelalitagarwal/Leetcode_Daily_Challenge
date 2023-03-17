/*
Link to the " Implement Trie (Prefix Tree) " Problem ==>>  https://leetcode.com/problems/implement-trie-prefix-tree/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/_5dmDxPPBU4

*/

class Trie {
public:
    set<string> st;

    Trie(){}

    void insert(string word) {
        st.insert(word);
    }

    bool search(string word) {
        return st.find(word) != st.end();
    }
    
    bool startsWith(string prefix) {

        auto it = st.lower_bound(prefix);
        if(it == st.end()) 
            return false;
        for(int i = 0;i<prefix.size();i++){
            if(prefix[i] != (*it)[i]){
                return false;
            }
        }
        return true;
    }
};