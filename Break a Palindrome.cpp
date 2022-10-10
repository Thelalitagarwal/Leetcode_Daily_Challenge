class Solution {
public:
    string breakPalindrome(string p) {     
        int l = p.length();
        
        if(l==1)
            return "";
        
        int s = 0, e = l/2;

        bool changed = false;
        
        while(s<e) {
            if(p[s] != 'a') {
                p[s] = 'a';
                changed = true;
                break;
            }            
            s++;
        }
        
        if(!changed)
            p[l-1] = 'b';
        
        return p;
    }
};