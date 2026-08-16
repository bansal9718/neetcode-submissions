class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {

        unordered_map<int,int>mp;
        vector<vector<pair<int, int>>> adj(n);
        
        //Generating the adjacency list
      
            for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt}); 
        }

        vector<int>dist(n,INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>q;
        q.push({0,src});

        while(!q.empty()) { 

            int node = q.top().second;
            int wt = q.top().first;

            q.pop();

            for(auto it:adj[node]) { 
                int v = it.first;
                int edWt = it.second;

                if(dist[v] > edWt + dist[node]) { 
                    dist[v] = edWt + dist[node];
                    q.push({dist[v],v});
                }
            }




        }

      for(int i=0;i<n;i++) { 
          if(dist[i]!=INT_MAX) { 
            mp[i] = dist[i];
          } else{
            mp[i] = -1;
          }
      }
      return mp;
    }
};
