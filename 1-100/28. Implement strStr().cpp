#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string s, string p) {
        if(p.size() == 0) return 0;
        int n = s.size() , m = p.size();
        s = " "+s; p = " "+p;
        vector<int> next(m+1);
        for(int i = 2 , j = 0 ; i <= m ; i++ ){
            while(j && p[i] != p[j+1] ) j = next[j];
            if(p[i] == p[j+1] ) j++;
            next[i] = j;
        }

        for(int i = 1 , j = 0 ; i <= n ;i++){
            while(j && s[i] != p[j+1] ) j = next[j];
            if(s[i] == p[j+1]) j++;
            if(j == m) return i-m;
        }
        return -1;
    }
};


int main()
{
    Solution solution;
    cout << solution.strStr("aaaaa","aa") << endl;
    return 0;
}

/*

实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

 

说明：

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

 

示例 1：

输入：haystack = "hello", needle = "ll"
输出：2
示例 2：

输入：haystack = "aaaaa", needle = "bba"
输出：-1
示例 3：

输入：haystack = "", needle = ""
输出：0
 

提示：

0 <= haystack.length, needle.length <= 5 * 104
haystack 和 needle 仅由小写英文字符组成


*/