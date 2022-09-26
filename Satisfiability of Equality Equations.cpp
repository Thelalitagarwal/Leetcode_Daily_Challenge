class Solution {
public:
    vector<int> parent;
    int find(int node){
        return parent[node] == -1?node:parent[node] = find(parent[node]);
    }
    void takeUnion(int a,int b){
        int x = find(a),y = find(b);
        if(x!=y) parent[x] = y;
    }
    bool equationsPossible(vector<string>& equations) {
        parent = vector<int>(26,-1);
        for(auto eq:equations)
            if(eq[1] == '=')takeUnion(eq[0]-'a',eq[3]-'a');
        for(auto eq:equations)
            if(eq[1] == '!' and find(eq[0]-'a') == find(eq[3]-'a'))return false;
        return true;
    }
};