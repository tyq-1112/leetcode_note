#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n,vector<int>(n));
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        for(int i=1,x=0,y=0,d=0;i<=n*n;i++){
            res[x][y] = i;
            int a = x+dx[d] , b = y+dy[d];
            if(a<0 || a>=n || b<0 || b>=n || res[a][b]){
                d = (d+1)%4;
                a = x+dx[d] , b = y+dy[d];
            }
            x = a , y =b;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    return 0;
}

/*

给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。



示例 1：


输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]


提示：

1 <= n <= 20


*/