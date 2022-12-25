class Solution {
public:
    bool row(vector<vector<int> >& a, int n){
        int r1=0;
        for(int i=0;i<n;i++){
            r1+=a[0][i];
        }
        for(int i=1;i<n;i++){
            int r=0;
            for(int j=0;j<n;j++){
                r+=a[i][j];
            }
            if(r!=r1){
                return false;
            }
        }
        return true;
    }
    bool col(vector<vector<int> >& a, int n){
        int c1=0;
        for(int i=0;i<n;i++){
            c1+=a[i][0];
        }
        for(int i=1;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                c+=a[j][i];
            }
            if(c!=c1){
                return false;
            }
        }
        return true;
    }
    bool dia(vector<vector<int> >& a, int n){
        int d1=0,d2=0;
        for(int i=0;i<n;i++){
            d1+=a[i][n-1-i];
        }
        for(int i=0;i<n;i++){
            d2+=a[i][i];
        }
        return (d1==d2);
    }
    long long int MissingNo(vector<vector<int> >& a) {
    long long int ans=0,r,c;
    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0){
                r=i;
                c=j;
            }
        }
    }
    if(r==0){
        for(int i=0;i<n;i++){
            ans+=(a[1][i]-a[0][i]);
        }
        a[r][c]=ans;
    }
    else{
        for(int i=0;i<n;i++){
            ans+=(a[0][i]-a[r][i]);
        }
        a[r][c]=ans;
    }
    if(row(a,n) && col(a,n) && dia(a,n) && ans>0){
        return ans;
    }
    return -1;
    }
};