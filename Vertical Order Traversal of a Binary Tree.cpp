class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> m;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* value=p.first;
            int x=p.second.first,y=p.second.second;
            m[x][y].insert(value->val);
            if(value->left){
                q.push({value->left,{x-1,y+1}});
            }
            if(value->right){
                q.push({value->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto q: m){
            vector<int> col;
            for(auto z: q.second){
                col.insert(col.end(),z.second.begin(),z.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};