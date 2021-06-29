#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

   
    stack<int> num;   //数字
    stack<char> op;   //操作符
    int calculate(string rs) {
        string s;
        for (auto c: rs)if (c != ' ')s += c;

        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == ' ') continue;
            if(s[i] == '(') op.push(s[i]);
            else if(isdigit(s[i])){
                int res = 0 , j = i;
                while(j<s.size() && isdigit(s[j])) res = res*10 + (s[j++] - '0');
                num.push(res);
                i = j-1;
            }else if(s[i] ==')'){
                while(op.top() != '(') eval();
                op.pop();
            }else{
                //"+48 + -48"
                if (!i || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')  // 特殊处理符号和正号
                    num.push(0);
                while(op.size() && op.top() !='(') eval();
                op.push(s[i]);
            }
        }
        
        while(op.size()) eval();
        return num.top();
    }

    void eval(){
        int a = num.top() ; num.pop();
        int b = num.top() ; num.pop();
        char x = op.top(); op.pop();
        int res = 0;
        if(x == '+') res = a+b;
        else res = b-a;
        num.push(res);
    }
};



/*
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

 

示例 1：

输入：s = "1 + 1"
输出：2
示例 2：

输入：s = " 2-1 + 2 "
输出：3
示例 3：

输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23
 

提示：

1 <= s.length <= 3 * 105
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
s 表示一个有效的表达式

*/
