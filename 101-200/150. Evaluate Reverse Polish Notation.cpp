#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        // +201   -202  *203   /204
        for(string x : tokens){
            int op = getnum(x);
            if(op <= 200) st.push(op);
            else{
                int a = st.top() ; st.pop();
                int b = st.top() ; st.pop();
                if(op == 201) st.push(b+a);
                else if(op == 202) st.push(b-a);
                else if(op == 203) st.push(b*a);
                else st.push(b/a);
            }
        }
        return st.top();
    }

    int getnum(string s){
        if(s == "+") return 201;
        if(s == "-") return 202;
        if(s == "*") return 203;
        if(s == "/") return 204;
        int ans = 0;
        bool f = 0;
        for(char ch : s){
            if(ch == '-') f = 1;
            else if(ch>='0' && ch <= '9') ans = ans*10 + (ch-'0');
        }
        if(f) ans = -ans;
        return ans;
    }
};
/*

根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

 

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 

示例 1：

输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：

输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
示例 3：

输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：
该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

提示：

1 <= tokens.length <= 104
tokens[i] 要么是一个算符（"+"、"-"、"*" 或 "/"），要么是一个在范围 [-200, 200] 内的整数
*/