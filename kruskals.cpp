#include <bits/stdc++.h>
using namespace std;
struct edge
{
	int w,i,j;
};
bool comp(edge a,edge b){
	return a.w<b.w;
}
int findPar(vector<int> &par,int i)
{
	if(par[i]==i)
		return i;
	return par[i]=findPar(par,par[i]);
}
void unionn(vector<int> &par,vector<int> &rank,int i,int j)
{
	int u,v;
	u=findPar(par,i);
	v=findPar(par,j);
	if(rank[u]>rank[v])
		par[v]=u;
	else if(rank[u]<rank[v])
		par[u]=v;
	else
	{
		par[v]=u;
		rank[u]++;
	}
}

int main() {
    // Write your code here
	int v,e;
	cin>>v>>e;
	edge ed[e];
	vector<int> par(v),rank(v,0);
	for(int i=0;i<v;i++)
		par[i]=i;
	for(int i=0;i<e;i++)
	{
		cin>>ed[i].i>>ed[i].j>>ed[i].w;
	}
	sort(ed,ed+e,comp);
	for(int i=0;i<e;i++)
	{
		if(findPar(par,ed[i].i)!=findPar(par,ed[i].j))
		{
			unionn(par,rank,ed[i].i,ed[i].j);
			int l=min(ed[i].i,ed[i].j),h=max(ed[i].i,ed[i].j);
			cout<<l<<" "<<h<<" "<<ed[i].w<<"\n";
		}
	}
}