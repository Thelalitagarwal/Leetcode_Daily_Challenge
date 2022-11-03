class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        unordered_map<string,int> ma;
        for(int i=0;i<words.size();i++){
            if(ma[words[i]]>0){
                ans+=4;
                ma[words[i]]--;
                if(ma[words[i]]==0){
                    ma.erase(words[i]);
                }
            }
            else{
                reverse(words[i].begin(),words[i].end());
                ma[words[i]]++;
            }
        }
        for(auto it:ma){   
            string s=it.first;
            if(s[0]==s[1]){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};