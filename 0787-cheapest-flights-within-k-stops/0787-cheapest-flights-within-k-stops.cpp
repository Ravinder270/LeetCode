class Solution {
public:
    // Dijkstra with DP    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create adjacenct list where adj[u] consists of a pair (v, weight from u to v )
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i: flights){
            adj[i[0]].push_back({i[1], i[2]});
        }
        
        // create a 2D distance vector (acts like DP), where each element (dis[i][j]) represents the distance of 'i' from 'src' when there are 'j' stops left.
        vector<vector<int>> dis(n+1, vector<int>(k+1,INT_MAX));
        
        
        // Dijkstra starts
        
        // Create a set (acts like priority queue) which holds { present weight or distance , { node, remaining stops } }
        set<pair<int,pair<int,int>>> se;
        // distance of src from src is 0 and there are k stops left
        se.insert({0,{src, k}});
        dis[src][k] = 0; // distance of src is 0 when k stops are left
        
        while(!se.empty()){
            // present element
            pair<int,pair<int,int>> pres = *(se.begin());
            // poping out pres
            se.erase(se.begin());
            
            int u = pres.second.first;
            // if reached dst. continue
            if( dst == u ) continue;
            
            // looping through the children of u ( i.e, all the v's )
            for(pair<int,int> i : adj[u]){
                
                int presWeight = pres.first;
                int costUtoV = i.second;
                int v = i.first;
                int remainingK = pres.second.second;
                
                // if presentWeght + cost of u-> v is less than distance of 'v' with 'remainingK' stops left.  
                if(  presWeight + costUtoV < dis[v][remainingK]  ){
                    if( remainingK > 0 || (v == dst && remainingK == 0)){
                        // updating dis[v][remainingK]
                        dis[v][remainingK] = presWeight + costUtoV;
                        // pushing it to our set.
                        se.insert({costUtoV + presWeight, { v, remainingK-1 }});
                    }
                }
                
            }
        }
        
        int ans = INT_MAX;
        // loop through all the 'k' possibilities of reaching 'dst' and choose the min
        for(int i  :dis[dst]) ans = min(i,ans);
        
        return ans == INT_MAX ? -1 : ans;
    }

};