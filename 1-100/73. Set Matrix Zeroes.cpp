#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //用第一行表示每一列是否存在0
        //用第一列表示每一行是否存在0
        //用两个变量维护第一行与第一列是否存在0
        bool row = false , col  = false;
        int n = matrix.size() , m = matrix[0].size();
        
        for(int i = 0 ; i < n ; i++){
            if(!matrix[i][0]) col = true;//第一列是否存在0
            if(i)for(int j = 1 ; j < m ; j++) {
                if(!matrix[i][j]) matrix[i][0] = 0;
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            if(!matrix[0][i])row = true;//第一行是否存在0
            if(i)for(int j = 1 ; j < n ; j++) {
                if(!matrix[j][i]) matrix[0][i] = 0;
            }
        }

        //看每一列
        for(int i = 1 ; i < m ; i++){
            if(!matrix[0][i])
                for(int j = 0 ; j < n ;j++) matrix[j][i] = 0;
        }
        //每一行
        for(int i = 1 ; i < n ; i++){
            if(!matrix[i][0])
                for(int j = 0 ; j < m ;j++) matrix[i][j] = 0;
        }

        if(col){
            for(int i = 0 ; i < n ; i++) matrix[i][0] = 0;
        }

        if(row){
            for(int i = 0 ; i < m ; i++) matrix[0][i] = 0;
        }
    }
};

/*

给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

进阶：

一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？
 

示例 1：


输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
示例 2：


输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

提示：

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1

*/