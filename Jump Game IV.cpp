class Solution {
public:
    int minJumps(vector<int>& arr) {
	    int n = arr.size(), ans = 0;
	    map<int, vector<int>> m;
	    vector<bool> vis(n, 0);
	    for (auto i = 0; i < n; i++) {
	    	m[arr[i]].push_back(i);
	    }
	    queue<int> q;
	    q.push(0);
	    vis[0] = true;
	    while (!q.empty()) {
	    	int sz = q.size();
	    	while (sz--) {
	    		int curr = q.front();
	    		q.pop();
	    		if (curr == n - 1) return ans;
	    		if (curr > 0) {
	    			if (!vis[curr - 1]) {
	    				q.push(curr - 1);
	    				vis[curr - 1] = true;
	    			}
	    		}
	    		if (curr < n - 1) {
	    			if (!vis[curr + 1]) {
	    				q.push(curr + 1);
	    				vis[curr + 1] = true;
	    			}
	    		}
	    		if(m[arr[curr]][0] == -1) continue;
	    		for (auto i : m[arr[curr]]) {
	    			if (!vis[i]) {
	    				q.push(i);
	    				vis[i] = true;
	    			}
	    		}
	    		m[arr[curr]] = {-1};
	    	}
	    	ans++;
	    }
	    return ans;
    }
};