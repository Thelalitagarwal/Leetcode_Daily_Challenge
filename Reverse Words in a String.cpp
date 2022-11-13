class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                if(temp.size()>0 && ans.size()>0){
                    ans+=' ';
                    ans+=temp;   
                }
                if(ans.size()==0 && temp.size()>0){
                    ans+=temp; 
                }
                temp="";
            }
            else{
                temp+=s[i];   
            }
        }
        reverse(temp.begin(),temp.end());
        if(temp.size()>0 && ans.size()>0){
            ans+=' ';
            ans+=temp;   
        }
        if(ans.size()==0 && temp.size()>0){
            ans+=temp; 
        }
        return ans;
    }
};