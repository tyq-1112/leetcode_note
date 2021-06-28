#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string t(s.rbegin(), s.rend());
        int n = s.size();
        s = ' ' + s + '#' + t;
        vector<int> ne(n * 2 + 2);
        for (int i = 2, j = 0; i <= n * 2 + 1; i ++ ) {
            while (j && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j ++ ;
            ne[i] = j;
        }
        int len = ne[n * 2 + 1];
        string left = s.substr(1, len), right = s.substr(1 + len, n - len);
        return string(right.rbegin(), right.rend()) + left + right;
    }
};




/*
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

 

示例 1：

输入：s = "aacecaaa"
输出："aaacecaaa"
示例 2：

输入：s = "abcd"
输出："dcbabcd"
 

提示：

0 <= s.length <= 5 * 104
s 仅由小写英文字母组成


*/
