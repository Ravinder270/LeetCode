//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

  public:
    // Function to return a list containing the DFS traversal of the graph.
    // tc = O(v + 2E) // no. of nodes;
    // sc = O(v);
    
    void dfs(int node,vector<int>&ls,int vis[],vector<int>adj[])
    {
        vis[node]=1;
        ls.push_back(node);
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
             dfs(it,ls,vis,adj);   
            }
        }
    }
    
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int>ls;
        int vis[v]={0};
        
        dfs(0,ls,vis,adj);
        return ls;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends