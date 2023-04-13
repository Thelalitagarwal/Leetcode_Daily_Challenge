/*
Link to the " Validate Stack Sequences " Problem ==>>  https://leetcode.com/problems/validate-stack-sequences/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/69LWjDSLLt8

*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int j = 0;
        for(auto val : pushed){
            st.push(val);
            while(st.size() > 0 && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
        return st.size() == 0;
    }
};