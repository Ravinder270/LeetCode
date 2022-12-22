class Solution {
public:
    pair<int,int> dfsUtil(int root,int parent, map<pair<int,int>,pair<int,int>> &cache,vector<vector<int>> &graph){
        
        if(cache.find(make_pair(root,parent)) != cache.end()){
            return cache[make_pair(root,parent)];
        }
        int ans = 0;
        int num_nodes = 1;
        for(auto child:graph[root]){
            if(child != parent){
                auto ret = dfsUtil(child,root,cache,graph);
                ans += (ret.first + ret.second);
                num_nodes += ret.second;
            }
        }
        cache[make_pair(root,parent)] = make_pair(ans,num_nodes);
        return make_pair(ans,num_nodes);
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> graph(N,vector<int>());
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> ans(N,0);
        map<pair<int,int>,pair<int,int>> cache;
        
        for(int i=0;i<N;i++){
            auto ret = dfsUtil(i,-1,cache,graph);
            ans[i] = ret.first;
        }
        
        return ans;
    }
};