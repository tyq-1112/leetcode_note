#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int cnt[26];
        memset(cnt,0,sizeof cnt);
        for(auto &x : s) cnt[x - 'a'] ++ ;
        for(auto &x : s) {
            if(cnt[x - 'a'] == 1) return x;
        }
        return ' ';
    }
};

/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "
 

限制：

0 <= s 的长度 <= 50000

*/