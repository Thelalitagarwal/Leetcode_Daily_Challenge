class Solution {
  public:
    int minimumInteger(int N, vector<int> &A) {
        long long int sum=0;
        for(auto it:A){
             sum+=it;
        }
        int ans=INT_MAX;
        for(int i=0;i<N;i++){
            if((long long)N*A[i]>=sum){
               ans=min(ans,A[i]);  
            }
        }
        return ans;
    }
};class Solution {
        bool DP_helper(unordered_map<string, bool> &isScramblePair, string s1, string s2)
        {
            int len = s1.size();
            bool res = false;
            if(0==len) return true;
            else if(1==len) return s1 == s2;
            else{
                if(isScramblePair.count(s1+s2)) return isScramblePair[s1+s2];
                if(s1==s2) res=true;
                else{
                    for(int i=1; i<len && !res; ++i){
                        res = res || (DP_helper(isScramblePair, s1.substr(0,i), s2.substr(0,i)) && DP_helper(isScramblePair, s1.substr(i,len-i), s2.substr(i,len-i)));
                       res = res || (DP_helper(isScramblePair, s1.substr(0,i), s2.substr(len-i,i)) && DP_helper(isScramblePair, s1.substr(i,len-i), s2.substr(0,len-i)));
                    }
                }
                return isScramblePair[s1+s2]= res;
                
            }
        }
    public:
        bool isScramble(string s1, string s2) {
           unordered_map<string, bool> isScramblePair;
           return DP_helper(isScramblePair, s1, s2);
        }
    };