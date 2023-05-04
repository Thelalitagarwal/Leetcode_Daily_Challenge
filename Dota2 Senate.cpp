/*
Link to the " Dota2 Senate " Problem ==>>  https://leetcode.com/problems/dota2-senate/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/IISyr8_xLIY

*/

class Solution {
public:
    string predictPartyVictory(string senate) {

        int n = senate.size();
        queue<int> radiant, dire;
        for(int i=0;i<n;i++){
            if(senate[i] == 'R'){
                radiant.push(i);
            }
            else{
                dire.push(i);
            }
        }
        if(radiant.size() == 0){
            return "Dire";
        }
        else if(dire.size() == 0){
            return "Radiant";
        }
        while(!radiant.empty() && !dire.empty()){
            if(radiant.front() < dire.front()){
                dire.pop();
                int r = radiant.front();
                radiant.push(r+n);
                radiant.pop();
                
            }
            else{
                radiant.pop();
                int d =  dire.front();
                dire.pop();
                dire.push(d+n);
            }
        }
        return radiant.size() == 0 ? "Dire":"Radiant";
        
    }
};