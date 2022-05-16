#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool dfsCycle(int i,vector<int> adj[],vector<int> &vis,vector<int> &dfsvis)
    {
        vis[i]=1;
        dfsvis[i]=1;
        for(auto x:adj[i])
        {
            if(vis[x]==0)
            {
                if(dfsCycle(x,adj,vis,dfsvis))
                    return true;
            }
            else if(dfsvis[x]==1)
                return true;
        }
        dfsvis[i]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int> vis(v,0),dfsvis(v,0);
        for(int i=0;i<v;i++)
        {
            if(vis[i]==0)
            {
                if(dfsCycle(i,adj,vis,dfsvis))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends