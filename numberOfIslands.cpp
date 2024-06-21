/*

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1

Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2

Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue 
and other in orange.

Your Task:
You don't need to read or print anything. 
Your task is to complete the function numIslands() which takes the grid 
as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500

*/

#include<bits/stdc++.h>
using namespace std;

void BFS(int row, int col, vector<vector<int>>&vis,vector<vector<char>>& grid){

        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = 1;

        queue<pair<int,int>> q;

        q.push({row,col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();


            //traversing the neighbours and mark them if its a land

            for(int delrow = -1; delrow<=1; delrow++){
                for(int delcol = -1; delcol<=1; delcol++){
                    int nrow = row+delrow;
                    int ncol = col+delcol;

                    if(nrow>=0 && nrow < m && ncol>=0 && ncol < n && grid[nrow][ncol] == '1'
                    && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        int cnt = 0;

        for(int row = 0; row<m;row++){
            for(int col = 0; col<n; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    BFS(row,col,vis,grid);
                }
            }
        }
        return cnt;
}