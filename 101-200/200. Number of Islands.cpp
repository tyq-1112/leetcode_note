#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n , m , ans ;
    int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size() , m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i , j , grid);
                }
            }
        }
        return ans;
    }

    void dfs(int x , int y , vector<vector<char>>& grid){
        grid[x][y] = '0';
        for(int i = 0 ; i < 4 ; i++){
            int nx = dir[i][0] + x;
            int ny = dir[i][1] + y;
            if(nx >=0 && nx < n && ny>=0 && ny<m && grid[nx][ny] == '1') dfs(nx,ny,grid);
        }
    }
};


/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'


*/