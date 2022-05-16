#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    bool bfsCycle(int i,vector<int>& vis,vector<int> adj[])
    {
        vis[i]=1;
        queue<pair<int,int>> q;
        q.push({i,-1});
        int k,n,l;
        while(!q.empty())
        {
            k = q.front().first;
            l = q.front().second;
            q.pop();
            for(auto j:adj[k])
            {
                if(!vis[j]){
                    vis[j]=1;
                    q.push({j,k});
                }
                else if(j!=l)
                    return true;
            }
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
                if(bfsCycle(i,vis,adj))
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