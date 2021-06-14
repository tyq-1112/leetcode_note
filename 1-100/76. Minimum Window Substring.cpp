#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hs , ht;
        for(auto ch : t) ht[ch]++;

        string ans;
        int cnt = 0 ;  // 几个数
        //双指针
        for(int i = 0 , j = 0 ; i < s.size() ; i++){
            hs[s[i]]++;
            if(hs[s[i]] <= ht[s[i]]) cnt++;

            while(hs[s[j]] > ht[s[j]]) hs[s[j++]] -- ;

            if(cnt == t.size()){
                if(ans.empty() || i-j+1 < ans.size()) 
                ans = s.substr(j,i-j+1);
            }
        }
        return ans;
    }
};

/*

给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成
 

进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？

*/