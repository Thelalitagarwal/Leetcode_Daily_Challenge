class Solution {
public:
    vector<int> find(string a){
        vector<int> f;
        if(a.size()==0)
            return f;
        int ind=0;
        unordered_map<char,int> m;
        for(int i=0;i<a.size();i++){
            if(m.find(a[i])==m.end()){
                m.insert({a[i],ind++});
                f.push_back(m[a[i]]);
            }
            else{
                f.push_back(m[a[i]]);
            }
        }
        return f;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> p=find(pattern);
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            vector<int> w=find(words[i]);
            if(p==w)
                ans.push_back(words[i]);
        }
        return ans;
    }
};