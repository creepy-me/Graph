
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int i,int par,vector<int> &vis,vector<int> &tin,vector<int> &low,vector<int> adj[],int &timer,vector<int> &ans)
    {
        vis[i]=1;
        tin[i]=low[i]=timer++;
        int child=0;
        for(auto x:adj[i])
        {
            if(x==par)
                continue;
            if(!vis[x])
            {
                dfs(x,i,vis,tin,low,adj,timer,ans);
                low[i]=min(low[x],low[i]);
                if(low[x]>=tin[i] && par!=-1 && find(ans.begin(),ans.end(),i)==ans.end())
                    ans.push_back(i);
                child++;
            }
            else
            {
                low[i]=min(low[i],tin[x]);
            }
        }
        if(par==-1 && child>1 && find(ans.begin(),ans.end(),i)==ans.end())
            ans.push_back(i);
    }
  public:
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        // Code here
        vector<int> ans,vis(v,0),tin(v,0),low(v,0);
        int timer=0;
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
                dfs(i,-1,vis,tin,low,adj,timer,ans);
        }
        if(!ans.size()){
            ans.push_back(-1);
            return ans;
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends