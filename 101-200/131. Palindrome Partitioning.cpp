#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int M = 20;
    int dp[M][M];
    vector<vector<string>> res;
    vector<string> path;
    int n ;

    vector<vector<string>> partition(string s) {
        n = s.size();
        
        //预处理 i ~ j 是否为回文串
        for(int i=0;i<n;i++) dp[i][i] = true ;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(s[i]==s[j]&&(dp[i+1][j-1]||j-i<3 )) dp[i][j] = true;
            }
        }

        dfs(s , 0);
        return res;
    }

    void dfs(string s , int start){
        if(start == s.length()){
            res.push_back(path);
            return ;
        }
        for(int i=start ; i<s.length() ; i++){
            if(!dp[start][i]){    //剪枝
                continue ;
            }
            path.push_back(s.substr(start , i-start+1));
            dfs(s,i+1);
            path.pop_back();
        }
    }

};



/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。

 

示例 1：

输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例 2：

输入：s = "a"
输出：[["a"]]
 

提示：

1 <= s.length <= 16
s 仅由小写英文字母组成

*/