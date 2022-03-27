/*Graph representation in c++ using adjacency list.
Here it is assumed that vertices are 1 based indexed.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter no. of vertices and no. of edges- ";
    cin>>n>>m;
    vector<int> adj[n+1];
    int i,j,u,v;
    cout<<"\nEnter the edges- ";
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"Below is the adjacency list-\n";
    for(i=1;i<=n;i++)
    {
        cout<<i<<": ";
        for(auto x:adj[i])
            cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}