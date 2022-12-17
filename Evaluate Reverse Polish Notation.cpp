/*
Link to the "Evaluate Reverse Polish Notation" Problem ==>>  https://leetcode.com/problems/evaluate-reverse-polish-notation/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/RNns2yxMOiA 

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(string s:tokens) {
        if(s.size()>1 || isdigit(s[0])){
            st.push(stoi(s));
        } 
        else {
            long long int x2=st.top(); 
            st.pop();
            long long int x1=st.top(); 
            st.pop();
            switch(s[0]) {
                case '+': x1+=x2; break;
                case '-': x1-=x2; break;
                case '*': x1*=x2; break;
                case '/': x1/=x2; break;
                default : break;
            }
            st.push(x1);
        }
    }
    return st.top();
}
};