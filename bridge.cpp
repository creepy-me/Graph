#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    void dfs(int i,int par,int &timer,vector<int> adj[],vector<pair<int,int>>& edge,vector<int> &vis,vector<int> &tin,vector<int> &low)
    {
        vis[i]=1;
        int child=0;
        tin[i]=low[i]=timer++;
        for(auto x:adj[i])
        {
            if(x==par)
                continue;
            if(!vis[x])
            {
                dfs(x,i,timer,adj,edge,vis,tin,low);
                low[i]=min(low[i],low[x]);
                if(low[x]>tin[i])
                    edge.push_back({i,x});
            }else
                low[i]=min(low[i],tin[x]);
        }
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int v, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> tin(v,0),low(v,0), vis(v,0);
        vector<pair<int,int>> edge;
        int timer=0;
        for(int i=0;i<v;i++)
        {
            dfs(i,-1,timer,adj,edge,vis,tin,low);
        }
        // int n=edge.size();
        // for(int i=0;i<n;i++)
        // {
        //     if((edge[i].first==c && edge[i].second==d) || (edge[i].first==d && edge[i].second==c))
        //         return 1;
        // }
        pair<int,int> p1={c,d},p2={d,c};
        if(find(edge.begin(),edge.end(),p1)!=edge.end() || find(edge.begin(),edge.end(),p2)!=edge.end())
            return 1;
        return 0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends