/*
Link to the " Asteroid Collision " Problem ==>> https://leetcode.com/problems/asteroid-collision/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/maNWFhgFuoU

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++)
        {
            if(asteroids[i]>0 || st.empty()) 
                st.push(asteroids[i]);
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i]))
                    st.pop();
                
                if(!st.empty() && st.top()==abs(asteroids[i]))
                    st.pop();
                else if(st.empty() || st.top()<0)
                    st.push(asteroids[i]);
            }
        }
        vector<int> ans(st.size());
        for(int i=st.size()-1; i>=0; i--)
        {
            ans[i]=(st.top()); 
            st.pop();
        }
        return ans;
    }
};
