class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) 
			return {}; // Handle Corner Case
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root); 
        while (!q.empty())
        {
            int size = q.size(); 
            vector<int> currlevel;
            for(int i = 0 ; i < size ; i++)
            {
                Node* tmp=q.front() ;
                q.pop() ;
                currlevel.push_back(tmp->val) ;
                for (auto n : tmp -> children)
                     q.push(n); 
            }
            res.push_back(currlevel) ;
        }
        return res ;
    }
};
