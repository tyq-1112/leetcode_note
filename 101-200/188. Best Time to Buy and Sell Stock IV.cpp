#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n=prices.size();
        if(n<=1)    return 0;
        //因为一次交易至少涉及两天，所以如果k大于总天数的一半，就直接取天数一半即可，多余的交易次数是无意义的
        K=min(K,n/2);

        /*dp定义：dp[i][j][k]代表 第i天交易了k次时的最大利润，其中j代表当天是否持有股票，0不持有，1持有*/
        int dp[n][2][K+1] ;
        memset(dp , 0 , sizeof dp);
        for(int k=0;k<=K;k++){
            dp[0][0][k]=0;
            dp[0][1][k]=-prices[0];
        }

        /*状态方程：
        dp[i][0][k]，
            当天不持有股票时，看前一天的股票持有情况 ,
        dp[i][1][k]，
            当天持有股票时，看前一天的股票持有情况*/
        for(int i=1;i<n;i++){
            for(int k=1;k<=K;k++){
                //               不持有股票        持有股票卖掉
                dp[i][0][k]=max(dp[i-1][0][k],dp[i-1][1][k]+prices[i]);
                //                持有股票         不持有股票买入
                dp[i][1][k]=max(dp[i-1][1][k],dp[i-1][0][k-1]-prices[i]);
            }
        }
        return dp[n-1][0][K];
    }
};


/*

给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 

提示：

0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000


*/