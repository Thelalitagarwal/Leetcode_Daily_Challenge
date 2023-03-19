/*
Link to the " Design Add and Search Words Data Structure " Problem ==>>  https://leetcode.com/problems/design-add-and-search-words-data-structure/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/4I3fIbl6s7w

*/

class TrieNode{
public:
    bool isCompleteWord;
    TrieNode* children[26];
    TrieNode() {
        isCompleteWord = false; 
        memset(children, 0, sizeof(children));
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    

    void addWord(string word) {

        TrieNode* node = root;
        for (char ch : word){
            int idx = ch - 'a';
            if(node->children[idx]==NULL) 
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isCompleteWord = true;
    }


    bool search(string word) {
        return searchHelper(word, root);
    }


    bool searchHelper(string word, TrieNode* node){

        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(ch == '.'){
                for(auto c: node->children)
                    if(c && searchHelper(word.substr(i+1), c)) 
                        return true;
                return false;
            }
            int idx = ch - 'a';
            if(node->children[idx]==NULL) 
                return false;
            node = node->children[idx];
        }
        return node->isCompleteWord;
    }
};