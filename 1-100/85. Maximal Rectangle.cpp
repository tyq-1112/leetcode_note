#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size() , m = matrix[0].size() , res = 0;
        int dp[n][m];
        memset(dp,0,sizeof dp);

        //从左至右看最大子矩形
        for(int i = 0 ; i <n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(!j) dp[i][j] = matrix[i][j]-'0';
                else if(matrix[i][j]=='1') dp[i][j] = dp[i][j-1]+1;
                res = max(res , dp[i][j]);
            }
        }
        // 1 0 1 1 1
        // 0 1 0 1 0
        // 1 1 0 1 1
        // 1 1 0 1 1
        // 0 1 1 1 1
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }

        for(int i = 1 ; i < n ; i++){
            for(int  j =0 ; j < m ;j++){
                if(matrix[i][j]=='1'){
                    int x = dp[i][j];
                    for(int k=i;k>=0&&x;k--){   //往上看能构成的最大矩形
                        x = min(x , dp[k][j]);
                        int ans = (i-k+1)*x;
                        res = max(res , ans);
                        //cout<<i<<" "<<j<<" "<<j<<" "<<ans<<endl;
                    }
                }
            }
        }
        return res;
    }
};

/*
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

 

示例 1：


输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。
示例 2：

输入：matrix = []
输出：0
示例 3：

输入：matrix = [["0"]]
输出：0
示例 4：

输入：matrix = [["1"]]
输出：1
示例 5：

输入：matrix = [["0","0"]]
输出：0
 

提示：

rows == matrix.length
cols == matrix[0].length
0 <= row, cols <= 200
matrix[i][j] 为 '0' 或 '1'

*/