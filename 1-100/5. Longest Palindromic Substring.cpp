#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int n = s.size() ;
		int start = 0 , ans = 1;
        int dp[n+1][n+1];   //dp[i][j] 表示 i~j 是否为回串
        memset(dp, 0, sizeof dp);
        for(int i = 0 ; i < n ; i++) dp[i][i] = 1;
        
        for(int j = 1 ; j < n ; ++j){
            for(int i = 0 ; i < j ; ++i){
                if(s[i] != s[j]) dp[i][j] = 0;    //如果首尾不一样，不是回文串
                else{
                    if(j-i<3 ) dp[i][j] = 1;     //去掉头尾只有一个字符或者为空，肯定是回文
                    else if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];  //取决于去掉头尾的子串是不是回文
                }
                if(dp[i][j] && j-i+1 > ans){  
                    start = i;       //如果是回文串，记录最长的
                    ans = j-i+1;
                }
            }
        }
        return s.substr(start , ans);
    }
};

// int main()
// {
//     Solution solution;
//     cout<< solution.longestPalindrome("a") << endl;
//     return 0;
// }
/*
给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

示例 2：

输入：s = "cbbd"
输出："bb"

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成
*/
