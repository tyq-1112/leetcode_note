#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct node{
        int x,y;
    };
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int ans = 0;
    int movingCount(int m, int n, int k) {
        if(k==0) return  1;
        bool vis[m][n]; memset(vis,false,sizeof(vis));
        vis[0][0] = true; 
        queue<node> q; q.push({0,0}); ans++;
        while(!q.empty()){
            node now = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int nx = now.x+dir[i][0];
                int ny = now.y+dir[i][1];
                int sum = nx%10+nx/10+ny%10+ny/10;
                if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny] || sum>k) continue;
                q.push({nx,ny});ans++; vis[nx][ny] = true;
            }
        }
        return ans;
    }
};


/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 2：

输入：m = 3, n = 1, k = 0
输出：1
提示：

1 <= n,m <= 100
0 <= k <= 20

*/
