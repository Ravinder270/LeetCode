class Solution {
public:
    stack <int> s;
	void dfs(vector <int> adj[], vector <int> &vis, int root){
	    vis[root] = 1;
	    for(auto &i:adj[root]){
	        if(!vis[i])
	            dfs(adj, vis, i);
	    }
	    s.push(root);
	}
	void dfs1(vector <int> adj[], vector <int> &vis, int root, int level, int &ans){
        ans = max(ans, level);
	    vis[root] = 1;
	    for(auto &i:adj[root]){
	        if(!vis[i])
	            dfs1(adj, vis, i, level+1, ans);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector <int> vis(V);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
            }
        }
        vector <int> vec[V];
        for(int i=0; i<V; i++){
            for(auto &j:adj[i]){
                vec[j].push_back(i);
            }
        }
        fill(vis.begin(), vis.end(), 0);
        int c = 0;
        while(!s.empty()){
            int t = s.top();
            s.pop();
            if(!vis[t]){
                int ans = 0;
                dfs1(vec, vis, t, 1, ans);
                c = max(c, ans);
            }
        }
        return c;
    }
    int longestCycle(vector<int>& edges) {
        int V = edges.size();
        vector <int> adj[V];
        for(int i=0; i<V; i++){
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        int ans = kosaraju(V, adj);
        return ans == 1 ? -1 : ans;
    }
};