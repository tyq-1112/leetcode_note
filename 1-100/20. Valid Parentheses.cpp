#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:

    const static int N = 1e4+4;
    char st[N];

    bool isValid(string s) {
        int r = 1 ;
        st[0] = '#';
        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st[++r] = s[i];
            }else{
                char ch = st[r--];
                if(ch == '(') ch = ')';
                else if(ch == '[') ch = ']';
                else if(ch == '{') ch = '}';
                if(ch != s[i]) return false;
            }
        }
        if(r==1) return true;
        return false;
    }
};

int main()
{
    Solution solution;
    cout << solution.isValid("({})") << endl;
    return 0;
}

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true
 

提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成

*/