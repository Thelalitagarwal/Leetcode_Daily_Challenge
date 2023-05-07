/*
Link to the " Find the Longest Valid Obstacle Course at Each Position " Problem ==>>  https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/o84Vb1qbZms

*/

class Solution {
 public:

  int firstGreater(const vector<int>& A, int target) {
    return upper_bound(begin(A), end(A), target) - begin(A);
  }

  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    
    vector<int> ans;
    vector<int> tail;
    for (int obstacle : obstacles){
      if (tail.empty() || obstacle >= tail.back()) {
        tail.push_back(obstacle);
        ans.push_back(tail.size());
      } 
      else {
        int index = firstGreater(tail, obstacle);
        tail[index] = obstacle;
        ans.push_back(index + 1);
      }
    }
    return ans;
  }
};