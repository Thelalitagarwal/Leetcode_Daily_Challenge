/*
Link to the " Minimum Time to Complete Trips " Problem ==>>  https://leetcode.com/problems/minimum-time-to-complete-trips/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/nOfq3MgbFQI

*/

typedef long long ll; 
class Solution {

    bool check(vector<int> &time, ll mid, ll t){
        ll trips = 0;
        for(auto &i:time){
            trips += (mid/i);
            if(trips >= t) return true;
        }
        return false;
    }

public:
    long long minimumTime(vector<int>& time, int t) {

        int n = time.size();
        sort(time.begin(), time.end());
        ll l = (ll)time[0];
        ll r = (ll)time[n-1]*(ll)t;
        while(l<r){
            ll mid = l + (r-l)/2;
            if(check(time, mid, (ll)t)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};