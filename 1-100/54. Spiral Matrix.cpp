#include <bits/stdc++.h>

using namespace std;
const int N = 3e4+10;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if(!n) return res;
        int m = matrix[0].size();

        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        vector<vector<bool>> st(n,vector<bool>(m));

        for(int i=0 ,x = 0,y=0,d=0;i<n*m;i++){
            res.push_back(matrix[x][y]);
            st[x][y] = true;
            int a = x+dx[d];
            int b = y+dy[d];
            if(a<0 || a>=n || b<0 || b>=m || st[a][b]) {
                d++;
                d = d%4;
                a = x+dx[d];
                b = y+dy[d];
            }
            x = a , y = b;
        }
        return res;
    }
};


int main()
{
    Solution1 solution1;
    
    return 0;
}

/*

给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 

示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：


输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100


*/