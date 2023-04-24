/*
Link to the " Last Stone Weight " Problem ==>>  https://leetcode.com/problems/last-stone-weight/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/5P26CXY-Rbk

*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> p;
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }
        while(p.size()>1){
            int ans=p.top();
            p.pop();
            ans=ans-p.top();
            p.pop();
            p.push(ans);
        }
        return p.top();
    }
};