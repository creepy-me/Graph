/*DFS Traversal of graph in c++.
Here it is assumed that vertices are 0 based indexed.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
void dfs(int i,vector<int>& ans,vector<int>& vis,vector<int> adj[])
    {
        ans.push_back(i);
        vis[i]=1;
        for(auto x:adj[i])
        {
            if(!vis[x])
                dfs(x,ans,vis,adj);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
                dfs(i,ans,vis,adj);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	// for multiple graphs
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u); // uncomment this for undirected graoh 
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends