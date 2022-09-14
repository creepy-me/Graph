//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> row={0,0,1,-1};
vector<int> col={1,-1,0,0};
class Solution
{
    public:
    bool valid(int x,int y,int n)
    {
        return (x<n && x>=0 && y<n && y>=0);
    }
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,1e8));
        dis[0][0]=grid[0][0];
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty())
        {
            pair<int,pair<int,int>> tp=pq.top();
            int x=tp.second.first,y=tp.second.second;
            pq.pop();
            if(vis[x][y])
                continue;
            vis[x][y]=1;
            for(int i=0;i<4;i++)
            {
                if(valid(x+row[i],y+col[i],n))
                {
                    if(dis[x+row[i]][y+col[i]]>grid[x+row[i]][y+col[i]]+dis[x][y])
                    {
                        dis[x+row[i]][y+col[i]]=grid[x+row[i]][y+col[i]]+dis[x][y];
                        pq.push({dis[x+row[i]][y+col[i]],{x+row[i],y+col[i]}});
                    }
                }
            }
        }
        return dis[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends