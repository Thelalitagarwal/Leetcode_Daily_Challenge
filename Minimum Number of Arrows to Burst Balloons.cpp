/*
Link to the "Minimum Number of Arrows to Burst Balloons" Problem ==>>  https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/ZuB6rZqC11M 

*/

bool comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if(points.size() == 0) 
            return 0; 
        sort(points.begin(), points.end(), comp);
        int arrows = 1;
        int last = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > last){
                arrows++;
                last = points[i][1];
            }
        }
        return arrows;
    }
};