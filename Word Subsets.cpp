class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        int a[26]={0};
        for(int i=0;i<words2.size();i++){
            int s[26]={0};
            for(int j=0;j<words2[i].size();j++){
                s[words2[i][j]-'a']=s[words2[i][j]-'a']+1;
            }
            for(int j=0;j<26;j++){
                a[j]=max(a[j],s[j]);
            }
        }
        
        for(int i=0;i<words1.size();i++){
            int t[26]={0};
            for(int j=0;j<words1[i].size();j++){
                t[words1[i][j]-'a']=t[words1[i][j]-'a']+1;
            }
            int j=0;
            for(j=0;j<26;j++){
                if(t[j]<a[j]){
                    break;
                }
            }
            if(j==26){
                result.push_back(words1[i]);
            }
        }
        return result;
    }
};