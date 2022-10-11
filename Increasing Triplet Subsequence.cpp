class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3){ 
            return false;
        }
        int x = INT_MAX, y = INT_MAX;
        for(int i : nums) {
            if(i <= x)
                x = i;           
            else if(i <= y)    
                y = i;           
            else            
                return true;   
        }
        return false;
    }
};