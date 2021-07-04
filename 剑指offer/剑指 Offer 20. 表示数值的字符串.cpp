#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int l = 0, r = s.size() - 1;
        //去掉前后空格
        while (l <= r && s[l] == ' ') l ++ ;
        while (l <= r && s[r] == ' ') r -- ;
        if (l > r) return false;
        
        s = s.substr(l, r - l + 1);
        //去掉正负号
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);
        //如果只有正负号，false
        if (s.empty()) return false;
        //如果只有一个点，或者.e || .E 返回false
        if (s[0] == '.' && (s.size() == 1 || s[1] == 'e' || s[1] == 'E'))
            return false;

        //记录点和e的次数
        int dot = 0, e = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] == '.') {
                //如果出现多个点或者e ，fasle
                if (dot > 0 || e > 0) return false;
                dot ++ ;
            } else if (s[i] == 'e' || s[i] == 'E') {
                //如果e的前面没东西或者后面没东西，或者多个e ，false
                if (!i || i + 1 == s.size() || e > 0) return false;
                //如果e的后面是正负号
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    //但是后面没东西了，返回false
                    if (i + 2 == s.size()) return false;
                    i ++ ;
                }
                e ++ ;
                //不合法
            } else if (s[i] < '0' || s[i] > '9') return false;
        }
        return true;
    }
};



/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：

若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
 

示例 1：

输入：s = "0"
输出：true
示例 2：

输入：s = "e"
输出：false
示例 3：

输入：s = "."
输出：false
示例 4：

输入：s = "    .1  "
输出：true
 

提示：

1 <= s.length <= 20
s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' ' 或者点 '.' 。

*/
