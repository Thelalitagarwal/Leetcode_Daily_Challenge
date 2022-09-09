class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
			if(a[0]==b[0])return a[1]>b[1];
			return a[0]<b[0];
		}
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
			sort(properties.begin(),properties.end(),comp);
			int maxdef=INT_MIN;
			int count=0;
			for(int i=n-1;i>=0;i--){
				if(properties[i][1]<maxdef) count++;
				maxdef=max(maxdef,properties[i][1]);
			}
			return count;
    }
};