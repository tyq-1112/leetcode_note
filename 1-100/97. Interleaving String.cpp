#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size() , m = s2.size() , len = s3.size();
        if(n+m != len) return false;
        s1 = ' '+s1;s2 = ' '+s2;s3 = ' '+s3;
        vector<vector<bool>> f(n+1,vector<bool>(m+1));

        for(int i = 0 ; i <= n ;i++){
            for(int j = 0 ; j <= m ;j++){
                if(!i && !j) f[i][j] = true;
                else {
                    if(i && s1[i] == s3[i+j]) f[i][j] = f[i-1][j];
                    if(j && s2[j] == s3[i+j]) f[i][j] = f[i][j] || f[i][j-1];
                }
            }
        }
        return f[n][m];
    }
};


/*

给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
提示：a + b 意味着字符串 a 和 b 连接。

 

示例 1：


输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
示例 2：

输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false
示例 3：

输入：s1 = "", s2 = "", s3 = ""
输出：true
 

提示：

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1、s2、和 s3 都由小写英文字母组成


*/