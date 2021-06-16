#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        memset(dp,0,sizeof dp);
        dp[0] = dp[1] = 1;
        // f(i) : 以i为根结点的bst个数
        // dp[n] : n个结点组成bst的个数
        // DP[n] = f(0) + f(1) + f(2) + ...f(n)
        // 当 i 为根节点时，其左子树节点个数为 i-1 个，右子树节点为 n-i，则 dp[n] = dp[i-1] * dp[n-i]
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};



/*

给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

 

示例 1：


输入：n = 3
输出：5
示例 2：

输入：n = 1
输出：1
 

提示：

1 <= n <= 19


*/