class Solution {
public:
    int m,n;
    
    bool s(vector<vector<bool>>& ocean, int i, int j, vector<vector<int>>& ht){
        
        if (i<0 || j<0 || i==m || j==n) return false;
        
        if (ocean[i][j]) return true;
        
        
        int k = ht[i][j];
        
        ht[i][j]=100004;
        
        bool zz = false;
        
        
        if (i>0 && ht[i-1][j]<=k)   zz = zz || s(ocean,i-1,j,ht);
        
        if (j>0 && ht[i][j-1]<=k)   zz = zz || s(ocean,i,j-1,ht);
        
        if (i<m-1 && ht[i+1][j]<=k) zz = zz || s(ocean,i+1,j,ht);
        
        if (j<n-1 && ht[i][j+1]<=k) zz = zz || s(ocean,i,j+1,ht);
        
        ocean[i][j]=zz;
        ht[i][j]=k;
        return zz;
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        m = ht.size();
        n = ht[0].size();
        vector<vector<bool>> pac(m, vector<bool> (n,false));
        vector<vector<bool>> atl(m, vector<bool> (n,false));
        for (int i=0; i<m; i++){
            pac[i][0]=true;
            atl[i][n-1]=true;
        }
        for (int i=0; i<n; i++){
            pac[0][i]=true;
            atl[m-1][i]=true;
        }
        vector<vector<int>> res;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (s(pac,i,j,ht) && s(atl,i,j,ht))
                    res.push_back({i,j});
            }
        }
        return res;
    }
};