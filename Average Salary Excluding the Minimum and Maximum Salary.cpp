/*
Link to the " Average Salary Excluding the Minimum and Maximum Salary " Problem ==>>  https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/yhfPWZLYj8w

*/

class Solution {
public:
    double average(vector<int>& salary) {
        double total = 0;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<salary.size();i++){
            total+=salary[i];
            mini=min(mini,salary[i]);
            maxi=max(maxi,salary[i]);
        }
        total-=(mini+maxi);
        return total/(salary.size()-2);
    }
};