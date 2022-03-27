/*Graph representation in c++ using adjacency matrix.
Here it is assumed that vertices are 1 based indexed.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter no. of vertices and no. of edges- ";
    cin>>n>>m;
    int adj[n+1][n+1];
    memset( adj, 0, sizeof(adj));
    int i,u,v,j;
    cout<<"\nEnter the edges- ";
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    cout<<"\nBelow is the adjacency matrix- \n";
    cout<<" ";
    for(i=1;i<=n;i++)
        cout<<i<<" ";
    cout<<"\n";
    for(i=1;i<=n;i++)
    {
        cout<<i<<" ";
        for(j=1;j<=n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}