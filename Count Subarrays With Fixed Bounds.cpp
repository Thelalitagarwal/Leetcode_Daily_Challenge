/*
Link to the " Count Subarrays With Fixed Bounds " Problem ==>>  https://leetcode.com/problems/count-subarrays-with-fixed-bounds/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/zLv5H6CaTgE

*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res=0;
        int start=0,minstart=0,maxstart=0;
        bool minf=false,maxf=false;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(num<minK || num>maxK){
                minf=false;
                maxf=false;   
                start=i+1;
            }
            if(num==minK){
                minf=true;
                minstart=i;
            }
            if(num==maxK){
                maxf=true;

                maxstart=i;
            }
            if(minf && maxf){
                res+=(min(minstart,maxstart)-start+1);
            }
        }
        return res;
    }
};