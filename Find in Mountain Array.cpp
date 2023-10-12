/*
Link to the "Find in Mountain Array" Problem ==>> https://leetcode.com/problems/find-in-mountain-array/?envType=daily-question&envId=2023-10-12
   
Link to the complete Explaination Video ==>> https://youtu.be/ZQiQQdHINzw

*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

int peak(MountainArray & arr, int n){
    int start=0,end=n-1;
    int res=-1;

    while(start<end){
        int mid=start + (end-start)/2;
        if(arr.get(mid+1)>arr.get(mid)) 
            start=mid+1,res=mid+1;
        else
         end=mid;
    }
    return res;
}

int bs(int s,int e, MountainArray & arr, int target, bool flag){
    int res=-1;

    while(s<=e){

        int mid = s + (e-s)/2;
        if(target== arr.get(mid)){
            res=mid;
            if(flag) 
                s=mid+1;
            else e=mid-1;
        }
        else if(target>arr.get(mid)){
            if(flag) 
                e=mid-1;
            else 
                s=mid+1;
        }
        else{
            if(flag) s=mid+1;
            else e=mid-1;
        }
    }
    return res;
}
class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr){

       int n = arr.length();
       if(n<3) 
        return -1;

       int part = peak(arr,n); 

       int l = bs(0,part,arr,target,0);

       if(l!=-1) 
        return l;
        
       int r = bs(part,n-1,arr,target,1);
       return r;
  }
};