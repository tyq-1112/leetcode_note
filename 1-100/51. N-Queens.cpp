#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const static int M = 20;
    int row[M] , col[M]  , dg[2*M] , udg[2*M] , n;
    vector<vector<string>> ans;
    vector<string> res;

    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        res = vector<string>(n,string(n,'.'));
        dfs(0,0,0);
        return ans;
    }

    void dfs(int x , int y , int cnt){
        if(y==n) x++,y = 0;
        if(x==n){
            if(cnt == n)ans.push_back(res);
            return ;
        }
        if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
            res[x][y] = 'Q';
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
            dfs(x, y + 1, cnt + 1);
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
            res[x][y] = '.';
        }
        dfs(x,y+1,cnt);
    }
};

int main()
{
    Solution solution;
    return 0;
}

/*

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 

示例 1：


输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：

输入：n = 1
输出：[["Q"]]
 

提示：

1 <= n <= 9
皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上

*/