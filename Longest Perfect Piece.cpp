class Solution {
  public:
    int longestPerfectPiece(int a[], int n) {
        int lo=0, hi=0, ans=0;
        map<int, int> mp;
        while(hi<n) {
            mp[a[hi]]++;
            while((--mp.end())->first - mp.begin()->first > 1) {
                mp[a[lo]]--;
                if(mp[a[lo]]==0) mp.erase(a[lo]);
                lo++;
            }
            ans=max(ans, hi-lo+1);
            hi++;
        }
        return ans;
    }
};