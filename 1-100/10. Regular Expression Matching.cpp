#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        s = " "+s;
        p = " "+p;
        int n = s.size() , m = p .size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.') dp[i][j] = dp[i-1][j-1];  // 如果最后一位匹配，只要取决去前面的是否匹配
                else if(p[j-1] == '*'){    //等于*分两种情况
                    if(s[i-1] == p[j-2] || p[j-2] == '.'){
                        dp[i][j]=dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                        // dp[i][j-1] 匹配1个
                        // dp[i][j-2] 匹配0个
                        // dp[i-1][j] 匹配多个
                    } else {
                        // 如果*号前面那个去当前不匹配，*号只能代表 0 个 
                        //          a  :  ac*
                        dp[i][j] = dp[i][j-2];  
                    }
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution solution;
    cout << solution.isMatch("aab","c*a*b") << endl;
    return 0;
}

/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

 
示例 1：

输入：s = "aa" p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
示例 2:

输入：s = "aa" p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3：

输入：s = "ab" p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4：

输入：s = "aab" p = "c*a*b"
输出：true
解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5：

输入：s = "mississippi" p = "mis*is*p*."
输出：false
 

提示：

0 <= s.length <= 20
0 <= p.length <= 30
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
保证每次出现字符 * 时，前面都匹配到有效的字符

*/