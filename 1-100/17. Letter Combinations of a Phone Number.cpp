#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "") return ans;
        unordered_map<char, string> mp{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        if(digits.size() == 1) {
            for(auto t : mp[digits[0]]) ans.push_back({t});
            return ans;
        }
        
        queue<string> q;
        for(auto t : mp[digits[0]]) q.push({t});
        
        for(int i = 1 ; i < digits.size() ; i++){
            queue<string> tq;
            while( q.size() ){
                string ch = q.front() ; q.pop();
                for(auto t : mp[digits[i]]){
                    tq.push(ch + t);
                }
            }
            q = tq;
        }
        while(q.size()) {
            ans.push_back(q.front()) ; q.pop();
        }
        return ans;
    }
};

// int main()
// {
//     Solution solution;
    
//     return 0;
// }
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
 

提示：

0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。


*/