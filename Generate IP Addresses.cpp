class Solution{
  public:
  bool isvalid(string s){
        int n=s.length();
        if(n==0 || n>3 || (s[0]=='0' && n>1) || stoi(s)>255)return false;
        return true;
        
    }
    vector<string> genIp(string &s) {
        
        vector<string> ans;
        int n=s.length();
        if(n>12){
            return ans;
        }
        for(int i=1;i<n-2;i++){//1,2,3
            for(int j=i+1;j<n-1;j++){//2,3,4 / 3,4,5 / 4,5,6
                for(int k=j+1;k<n;k++){
                    string first=s.substr(0,i);
                    string sec=s.substr(i,j-i);
                    string third=s.substr(j,k-j);
                    string fourth=s.substr(k,n-k);
                    if(isvalid(first) && isvalid(sec) && isvalid(third) && isvalid(fourth)){
                        ans.push_back(first+"."+sec+"."+third+"."+fourth);
                    }
                }
            }
        }
        return ans;
    }
    

};