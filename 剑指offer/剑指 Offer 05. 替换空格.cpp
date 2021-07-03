#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {     //字符数组
        string array;   //存储结果
        
        for(auto &c : s){   //遍历原字符串
            if(c == ' '){
                array.push_back('%');
                array.push_back('2');
                array.push_back('0');
            }
            else{
                array.push_back(c);
            }
        }
        return array;
    }
};


/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：

0 <= s 的长度 <= 10000

*/
