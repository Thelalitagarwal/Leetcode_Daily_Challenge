class Solution {
public:
    
    string convert(string s, int numRows) {
        vector<vector<char>> a(numRows, vector<char>(s.size()));
        int row = 0, dir = true;
        for(int i = 0; i < s.size(); i++){
            a[row%numRows][i] = s[i];
            if(dir)
                ++row;
            else
                --row;
            
            if(row == numRows-1)
                dir = false;
            else if(row == 0)
                dir = true;
                
        }
        
        string r;
        for(auto x : a)
            for(auto y : x)
                if(isalpha(y) || y == '.' || y == ',')
                    r+=y;
        return r;
    }
};
