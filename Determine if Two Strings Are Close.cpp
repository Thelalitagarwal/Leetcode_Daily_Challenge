class Solution {
public:
    bool closeStrings(string str1, string str2) {
        unordered_map<char,int> m1,m2;
        if(str1.size()!=str2.size())
            return false;
        for(int i=0;i<str1.size();i++){
            m1[str1[i]]++;
        }
        for(int i=0;i<str2.size();i++){
            m2[str2[i]]++;
        }
        bool a[m1.size()];
        if(m1.size()!=m2.size()){
            return false;
        }
        vector<int> v1;
        vector<int> v2;
        vector<char> v3;
        vector<char> v4;
        for(auto it:m1){
            v1.push_back(it.second);
            v3.push_back(it.first);
        }
        for(auto it:m2){
            v2.push_back(it.second);
            v4.push_back(it.first);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());
        sort(v4.begin(),v4.end());
        if(v1==v2 && v3==v4)
            return true;
        return false;
    }
};