#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0 , pos = -1;  //答案和每段合法的开始位置
        stack<int>st;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(') st.push(i);
            else{
                if(st.size()){
                    st.pop();
                    if(st.size()) ans = max(ans , i-st.top());
                    else ans = max(ans , i-pos);
                }else{
                    pos = i;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.longestValidParentheses("()()()(())") << endl;
    return 0;
}

/*

给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

 

示例 1：

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
示例 2：

输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
示例 3：

输入：s = ""
输出：0
 

提示：

0 <= s.length <= 3 * 104
s[i] 为 '(' 或 ')'


*/