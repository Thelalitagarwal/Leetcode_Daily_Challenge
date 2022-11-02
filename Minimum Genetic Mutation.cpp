class Solution {
public:
    
    bool able(string b,string t){
        int c=0;
        if(b.size()!=t.size()){
            return false;
        }
        for(int i=0;i<t.size();i++){
            if(t[i]!=b[i]){
                c++;
            }
        }
        return c==1;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        int i=0;
        for(i=0;i<bank.size();i++){
            if(bank[i]==end){
                break;
            }
        }
        if(i==bank.size()){
            return -1;
        }
        queue<string> q;
        unordered_map<string,bool> ma;
        ma[start]=true;
        q.push(start);
        int ans=0;
        while(!q.empty()){
            ans++;
            int m=q.size();
            for(int j=0;j<m;j++){
                string temp=q.front();
                q.pop();
                for(int i=0;i<bank.size();i++){
                    if(ma[bank[i]]!=true){
                        
                        if(able(bank[i],temp)){
                            
                            if(bank[i]==end){
                                
                                return ans;
                            }
                            ma[bank[i]]=true;
                            
                            q.push(bank[i]);
                        }
                    }
                }
             }
        }
         return -1;
    }
};