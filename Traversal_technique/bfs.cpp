/*BFS Traversal of graph in c++.
Here it is assumed that vertices are 0 based indexed.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void bfs(int i,vector<int>& ans,vector<int>& vis,vector<int> adj[])
    {
        vis[i]=1;
        queue<int> q;
        q.push(i);
        int t;
        while(!q.empty())
        {
            t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto x:adj[t])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    q.push(x);
                }
                
            }
        }
    }
    
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        vector<int> vis(v,0);
        vector<int> ans;
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
                bfs(i,ans,vis,adj);
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
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends