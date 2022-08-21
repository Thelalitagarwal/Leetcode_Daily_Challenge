class Solution {
public:
    bool canReplace(string &stamp,string &target,int pos){
        int m=stamp.size(),n=target.size();
        for(int i=0;i<m;i++){
            if(target[i+pos]!='?' and target[i+pos]!=stamp[i])
                return false;
        }
        return true;
    }
    
    
    int replace(string &stamp,string &target,int pos){
        int cnt=0;
        int m=stamp.size(),n=target.size();
        for(int i=0;i<m;i++){
            if(target[i+pos]!='?'){
                cnt++;
                target[i+pos]='?';
            }
        }
        return cnt;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        
        vector<int> ans;
        
        int m=stamp.size(),n=target.size();
        
        int count=0;
        
        vector<int> vis(n+1,0);
        
        while(count!=n){
            bool flag=false;
            for(int i=0;i<=n-m;i++){
                if(!vis[i] and canReplace(stamp,target,i)){
                    vis[i]=1;
                    count+=replace(stamp,target,i);
                    flag=true;
                    ans.push_back(i);
                    if(count==n) break;
                }
            }
            if(!flag) return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};