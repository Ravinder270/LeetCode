class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> adj;
        for(int i = 0; i < n; i++){
            adj[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<int> vis(n);
        vis[0] = 1;
        int ans = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop();
                if(node == n - 1) return ans;
                for(auto&i:adj[arr[node]]){
                    if(!vis[i]){
                        vis[i] = 1;
                        q.push(i);
                    }
                }
                adj[arr[node]].clear();
                if(node && !vis[node - 1]) q.push(node - 1), vis[node - 1] = 1;
                if(node + 1 < n && !vis[node + 1]) q.push(node + 1), vis[node + 1] = 1;
            }
            ans++;
        }
        return ans;
    }
};