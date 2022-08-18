// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        int n=grid.size(),m=grid[0].size();
        vis[i][j]=1;
        for(int x=-1;x<2;x++){
            
            for(int y=-1;y<2;y++)
            {
                if((i+x>=0&&i+x<n&&j+y>=0&&j+y<m)&&grid[i+x][j+y]=='1'&&vis[i+x][j+y]==0)
                {
                    dfs(i+x,j+y,grid,vis);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='0')
                {
                    vis[i][j]=1;
                    continue;
                }
                else if(vis[i][j]==0)
                {
                    dfs(i,j,grid,vis);
                    // cout<<i<<" "<<j<<"\n";
                    ans++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends