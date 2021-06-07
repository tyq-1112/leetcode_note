#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> st;    //哈希记录字符是否存在
        int ans = 0 , left = 0;
        for(int i = 0; i < s.size(); i++){
			//滑动窗口
            while (st.find(s[i]) != st.end()){   
                st.erase(s[left]);
                left ++;
            }
            ans = max(ans,i-left+1);
            st.insert(s[i]);
    }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

0 <= s.length <= 5 * 10^4
s 由英文字母、数字、符号和空格组成
*/