class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>v;
        for(int i=0;i<rocks.size();i++)     v.push_back(capacity[i]-rocks[i]);
        sort(v.begin(),v.end());
        int i=0;
        while(additionalRocks>0 and i<v.size()){
            additionalRocks-=v[i];
            i++;
        }
        return additionalRocks<0 ? i-1 : i;
    }
};