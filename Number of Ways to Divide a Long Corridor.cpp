/*
Link to the "Number of Ways to Divide a Long Corridor" Problem ==>> https://leetcode.com/problems/knight-dialer/description/?envType=daily-question&envId=2023-11-27
   
Link to the complete Explaination Video ==>> https://youtu.be/8foC_AKxCsg

*/


class Solution {
public:
    int MOD=1000000007;
    int numberOfWays(string corridor) {

        int count;
        int pair=0;
        int current=0;
        vector<int> dividers;
        int first=INT_MAX;

        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                first=i;
                break;
            }
        }

        if(first==INT_MAX){
            return 0;
        }

        count=1;
        pair=1;
        current=0;

        for(int i=first+1;i<corridor.size();i++){

            if(corridor[i]=='S'){
                pair+=1;
                count+=1;
            }

            if(pair==3){
                dividers.push_back(current);

                pair=1;

                current=0;

            }

            if(pair==2){
                if(corridor[i]=='P'){
                    current+=1;
                }
            }
        }

        if(count%2!=0){
            return 0;
        }

        long long result=1;

        for(int i=0;i<dividers.size();i++){

            result*=(dividers[i]+1)%MOD;
            
            result%=MOD;
        }
        return result;
    }
};