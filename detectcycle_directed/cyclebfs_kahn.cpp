// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int> indegree(v,0);
	    for(int i=0;i<v;i++)
	    {
	        for(auto x:adj[i])
	            indegree[x]++;
	    }
	    queue<int> qt;
	    for(int i=0;i<v;i++)
	    {
	        if(indegree[i]==0)
	            qt.push(i);
	    }
	    int count = 0;
	    while(!qt.empty())
	    {
	        int node = qt.front();
	        qt.pop();
	        for(auto x:adj[node])
	        {
	            indegree[x]--;
	            if(indegree[x]==0)
	                qt.push(x);
	        }
	        count++;
	    }
	    if(count==v)
	        return false;
	    return true;
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