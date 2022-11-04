class Solution {
public:
    string reverseVowels(string s) {
        queue<int> q;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                q.push(i);
                st.push(s[i]);
            }
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                q.push(i);
                st.push(s[i]);
            }
        }
        
        for(int i=0;i<s.size();i++){
            if((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') && q.size()>0 && i==q.front()){
                s[i]=st.top();
                st.pop();
                q.pop();
            }
            if((s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') && q.size()>0 && i==q.front()){
                s[i]=st.top();
                st.pop();
                q.pop();
            }
        }
        return s;
    }
};