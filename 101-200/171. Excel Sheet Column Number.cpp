#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0 , n = columnTitle.size();
        for(int i = 0 ; i<n ; i++){
            int x = columnTitle[i]-'A'+1;
            ans+=(x*pow(26,n-i-1));
        }
        return ans;
    }
};


/*
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
示例 1:

输入: "A"
输出: 1
示例 2:

输入: "AB"
输出: 28
示例 3:

输入: "ZY"
输出: 701


*/