class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {

      int n = numCourses;

      vector<vector<int>>adj(n);
      vector<int>indegree(n,0);
      

      //Generating prerequisite graph
      for(auto it:arr) { 
        int v = it[0];
        int u = it[1];

        adj[u].push_back(v);
        indegree[v]++;
    }


      queue<int>q;

      for(int i=0;i<n;i++) { 
        if(indegree[i]==0) { 
            q.push(i);
        }
      }

 int count=0;
    while(!q.empty()) { 

        int node = q.front();
        q.pop();
       count++;
        for(auto it:adj[node]) { 
            
        indegree[it]--;
         if(indegree[it]== 0) { 
            q.push(it);
        } 
       
        
        }
     }

    
     return count==numCourses;
      

    }
};
