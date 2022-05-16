#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    bool dfsCycle(int i,int par,vector<int>& vis,vector<int> adj[])
    {
        vis[i]=1;
        int k,n,l;
            for(auto j:adj[i])
            {
                if(!vis[j]){
                    vis[j]=1;
                    if(dfsCycle(j,i,vis,adj))
                        return true;
                }
                else if(j!=par)
                    return true;
            }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int> vis(v,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                if(dfsCycle(i,-1,vis,adj))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends