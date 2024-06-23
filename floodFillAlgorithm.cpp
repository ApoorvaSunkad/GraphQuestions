/*
An image is represented by a 2-D array of integers, each integer 
representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) 
of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels 
connected 4-directionally to the starting pixel of the same color as the 
starting pixel, plus any pixels connected 4-directionally to those pixels 
(also with the same color as the starting pixel), and so on. 
Replace the color of all of the aforementioned pixels with the newColor.

Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function floodFill() which takes image, sr, sc and newColor as input paramater and returns the image after flood filling.
 

Expected Time Compelxity: O(n*m)
Expected Space Complexity: O(n*m)
 

Constraints:
1 <= n <= m <= 100
0 <= pixel values <= 10
0 <= sr <= (n-1)
0 <= sc <= (m-1)

*/

#include<bits/stdc++.h>
using namespace std;

void DFS(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, 
    int newColor, int delRow[], int delCol[], int initialColor){
        
        ans[row][col] = newColor;
        
        int n = image.size();
        int m = image[0].size();
        
        for(int i = 0; i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow< n && ncol >=0 && ncol < m 
            && image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor){
                
                DFS(nrow,ncol,ans,image,newColor,delRow,delCol,initialColor);
            }
        }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Code here 
    int initialColor = image[sr][sc];
    
    vector<vector<int>> ans = image;
    
    int delRow[] = {-1,0,+1,0};
    int delCol[] = {0,+1,0,-1};
    
    DFS(sr,sc,ans,image,newColor,delRow, delCol, initialColor);
    
    return ans;
}