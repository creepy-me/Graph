//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> row = {-1, 0, 0, 1};
vector<int> col = {0, -1, 1, 0};
class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 0)), vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int t = 0; t < 4; t++)
            {
                int a = x + row[t], b = y + col[t];
                if (a < 0 || a >= n || b < 0 || b >= m)
                {
                    continue;
                }
                if (grid[a][b] == 0 && !vis[a][b])
                {
                    vis[a][b] = 1;
                    dis[a][b] = 1 + dis[x][y];
                    q.push({a, b});
                }
            }
        }
        return dis;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends