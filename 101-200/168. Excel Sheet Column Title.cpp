#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 0)
        {   
            int x = columnNumber % 26 ;
            if(x == 0){
                res = 'Z' + res; 
                columnNumber = columnNumber/26 - 1; 
            }
            else{
                res = char('A'+(x- 1)) +res;
                columnNumber = columnNumber/26;
            }
        }
        return res;
    }
};

/*
给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
示例 1:

输入: 1
输出: "A"
示例 2:

输入: 28
输出: "AB"
示例 3:

输入: 701
输出: "ZY"

*/