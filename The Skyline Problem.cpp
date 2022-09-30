class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> temp;
        for(auto x:buildings){   
            temp.push_back({x[0], -x[2]});
            temp.push_back({x[1], x[2]});
        }
        sort(temp.begin(), temp.end());
        multiset<int, greater<int>> set;
        set.insert(0);
        int height=0;
        for(auto x: temp){
            int currX=x.first, currH=x.second;
            if(currH<0)
                set.insert(-currH);
            else 
                set.erase(set.find(currH));
            int top=*set.begin();
            if(height!=top){
                height=top;
                ans.push_back({currX, top});
            }
            
        }
        return ans;
    }
};