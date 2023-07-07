/*
Link to the " Maximize the Confusion of an Exam " Problem ==>> https://leetcode.com/problems/maximize-the-confusion-of-an-exam/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/YQlsxIcXASk

*/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        int ans=0,T=0,F=0,i=0;
        for(int j=0;j<answerKey.size();j++){
            if(answerKey[j]=='T') 
                T++;
            else 
                F++;
            if(min(T,F)>k){
                if(answerKey[i]=='T') 
                    T--;
                else 
                    F--;       
                i++;
            }
            ans=max(ans,T+F);
        }
        return ans;
    }
};