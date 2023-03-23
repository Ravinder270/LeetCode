class Solution {
private:
    //Same as Number of Islands
    void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node]=1;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
        
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       
       //base case when edges are lesser then minimum 
       if(connections.size()< n-1)
           return -1;
       
       vector<int>adj[n]; 
        //Creating a graph
       for(auto v:connections)
       {
          adj[v[0]].push_back(v[1]);
          adj[v[1]].push_back(v[0]);
       }
       
       int components=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                components++;
            }
        }
        
        return components-1;
        
    }
};