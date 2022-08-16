class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ma;
        for(int i=0;i<s.length();i++){
            ma[s[i]]++;
        }
        int ans=-1;
        for(int i=0;i<s.length();i++){
            if(ma[s[i]]==1){
                ans=i;
                break;
            }
        }
        return ans;
    }
};