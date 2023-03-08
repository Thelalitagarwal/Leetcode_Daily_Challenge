/*
Link to the " Koko Eating Bananas " Problem ==>>  https://leetcode.com/problems/koko-eating-bananas/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/g8AS-1vRsa4

*/

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int i=1, j=*max_element(piles.begin(), piles.end()), ans;
		while(i<=j){
			int mid=i+(j-i)/2;
			long long int cnt=0;
			for(int i=0; i<piles.size(); i++){
				if(piles[i]<mid){cnt++;}
				else{cnt+=((piles[i]/mid)+(piles[i]%mid!=0));}
			}
			if(cnt>h){
				i=mid+1;
			}
			else{
				j=mid-1;
			}
		}
		return i;
	}
};