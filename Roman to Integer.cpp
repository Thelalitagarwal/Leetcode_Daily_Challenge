class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            if(i + 1 < n && um[s[i]] < um[s[i+1]]) {
                ans += um[s[i+1]] - um[s[i]];
                i++;
            } else {
                ans += um[s[i]];
            }
        } 
        
        return ans;
    }
};