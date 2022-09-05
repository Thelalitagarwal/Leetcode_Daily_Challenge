class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> temp;
            int s = q.size();
            
            for(int i = 0; i < s; i++){
                temp.push_back(q.front()->val);
                
                Node* temp = q.front();
                q.pop();
                
                for(Node* child : temp->children)
                q.push(child);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};