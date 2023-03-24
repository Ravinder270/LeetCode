class Solution {
public:
    //My Steps
    //1. Storing edges in set
    //2. Making graph bidirectional
    //3.Using BFS traversal for traversing whole graph 
    //4. and incrementing count if the node is not visited and 
    //5. it is present in the set
    int minReorder(int n, vector<vector<int>>& connections){
        vector<int>adj[n+1];
        set<pair<int,int>>s;
        //Creating a graph as well as storing into the set
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            s.insert({it[0],it[1]});
        }
        
        //performing BFS
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
       /// vis[0]=1;
        int total=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            if(!vis[node])
            {
                vis[node]=1;
            for(auto it:adj[node])
            {
                
                     q.push(it);
               
                if(!vis[it] && s.count({node,it}))
                {
                    total++;
                    
                }   
            }
        }
        }
        return total;
        
    }
};