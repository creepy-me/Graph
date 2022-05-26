#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    void dfs(int node,vector<int> transpose[],vector<int> &done)
    {
        done[node]=1;
        for(auto x:transpose[node])
            if(!done[x])
                dfs(x,transpose,done);
    }
    void toposort(int i,vector<int> adj[],vector<int> &vis, stack<int> &topo)
    {
        vis[i]=1;
        for(auto x:adj[i])
            if(!vis[x])
                toposort(x,adj,vis,topo);
        topo.push(i);
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[])
    {
        //code here
        stack<int> topo;
        vector<int> vis(v,0),done(v,0);
        for(int i=0;i<v;i++)
            if(!vis[i])
                toposort(i,adj,vis,topo);
        vector<int> transpose[v];
        for(int i=0;i<v;i++)
        {
            for(auto x:adj[i])
                transpose[x].push_back(i);
        }
        int count=0;
        while(!topo.empty())
        {
            int node = topo.top();
            topo.pop();
            if(!done[node])
            {
                count++;
                dfs(node,transpose,done);
            }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends