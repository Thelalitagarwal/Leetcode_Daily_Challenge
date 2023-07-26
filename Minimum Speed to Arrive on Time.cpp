/*
Link to the " Minimum Speed to Arrive on Time " Problem ==>> https://leetcode.com/problems/minimum-speed-to-arrive-on-time/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/FvNtVJqEy50

*/


class Solution {
public:
    bool isPossible(vector<int>& arr, double hr, int mid){

        double time=0;

        for(int i=0;i<arr.size()-1;i++)
            time+=ceil((double)arr[i]/mid);

        time+=((double)arr.back()/mid);
        if(time<=hr) 
            return true;

        return false;       

    }

    int minSpeedOnTime(vector<int>& dist, double hour) {

        int s=1;
        int e=1e7;
        int ans=-1;

        while(s<=e){
            int mid=s+(e-s)/2;

            if(isPossible(dist,hour,mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};