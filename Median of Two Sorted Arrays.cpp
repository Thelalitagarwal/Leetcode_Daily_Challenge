// Link to the problem: https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=daily-question&envId=2023-09-21

// Link to the Solution: https://www.youtube.com/watch?v=qGwNn8tWLmE

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        int i=0,j=0;

        int n = (nums1.size()+nums2.size())/2;
        n++;

        while(ans.size()<=n && i<nums1.size() && j<nums2.size()){
            if(nums1[i]>nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
            }
        }
        while(ans.size()<=n && i<nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
        while(ans.size()<=n && j<nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
        if((nums1.size()+nums2.size())%2==0){
            return (double)(ans[n-1]+ans[n-2])/2;
        }
        return ans[n-1];
    }
};