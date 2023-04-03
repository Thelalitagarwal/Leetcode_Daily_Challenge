/*
Link to the " Boats to Save People " Problem ==>>  https://leetcode.com/problems/boats-to-save-people/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/cQHUQYE5k7E

*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int boatCount = 0;
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        while(left <= right){
            int sum = people[left] + people[right];
            if(sum <= limit){
                boatCount++;
                left++;
                right--;
            }
            else{
                boatCount++;
                right--;
            }
        }
        return boatCount;
    }
};