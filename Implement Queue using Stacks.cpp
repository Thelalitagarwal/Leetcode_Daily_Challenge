/*
Link to the "Implement Queue using Stacks" Problem ==>>  https://leetcode.com/problems/implement-queue-using-stacks/description/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/5bjAbpWaip4 

*/

class MyQueue {
private:
    stack<int> s1,s2;
public:
    MyQueue() { 
    }
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();   
        return res;
    }
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};