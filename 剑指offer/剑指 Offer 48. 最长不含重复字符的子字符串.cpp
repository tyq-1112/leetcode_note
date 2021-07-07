#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        int ans = 1;
        unordered_map<char,int> mp;

        int j = 0;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]] ++;
            while(mp[s[i]]>1) mp[s[j++]]--;
            ans = max(ans , i-j+1);
        }

        return ans;
    }
};


/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

 

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

提示：

s.length <= 40000

*/