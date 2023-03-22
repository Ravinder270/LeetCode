class Solution 
{
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
       //Creating adjaceny list
        vector<pair<int,int>>adj[n+1];
        
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
      
        //performing BFS
   vector<int>vis(n+1,0);
    queue<int> q;
     q.push(1);
     vis[1]=1;
     while(!q.empty())
     {
         int node=q.front();
         q.pop();
         
         for(auto it:adj[node])
         {
             if(!vis[it.first])
             {
                 vis[it.first]=1;
                 q.push(it.first);
             }
         }
     }
     
     //we traversed whole graph 
        //now we will be finding minimum path
        int mini=INT_MAX;
      for(int i=0;i<roads.size();i++)
      {
          if(vis[roads[i][0]] && vis[roads[i][1]] && roads[i][2]<mini)
                                     {
                                         mini=roads[i][2];
                                     }
      }
        return mini;
    }
};