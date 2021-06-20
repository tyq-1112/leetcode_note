#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        int dp[n] ;      // 状态dp[i]表示 0 ~ i 需要最少分割次数
        for(int i = 0 ; i<n ; i++) dp[i] = i;   //初始值，最大，长度为n的字符串，最多切割n-1次

        int f[n][n];    //状态f[i][j] 表示 i ~ j 是否为回文串
        memset(f , 0 , sizeof f);

        for(int j=1;j<n;j++){
            for(int i=0;i<=j;i++){
                if(s[i]==s[j] && (j-i<3 || f[i+1][j-1])){ 
                    f[i][j]=true;
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(f[0][i]) {
                dp[i] = 0;   //如果 0 ~ i 是回文串，不需要切割
                continue;
            }
            for(int j = 0 ; j < i ; j++){
                if(f[j+1][i]) {
                    dp[i] = min(dp[i] , dp[j]+1);
                }
            }
        }

        return dp[n-1];
    }
};


/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。

返回符合要求的 最少分割次数 。

 

示例 1：

输入：s = "aab"
输出：1
解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
示例 2：

输入：s = "a"
输出：0
示例 3：

输入：s = "ab"
输出：1
 

提示：

1 <= s.length <= 2000
s 仅由小写英文字母组成


*/