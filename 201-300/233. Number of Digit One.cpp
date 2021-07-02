#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1) {
            return 0;
        }

        long digit = 1;
        int high = n / 10, cur = n % 10, low = 0;
        int res = 0;

        while (high != 0 || cur != 0) {
            if (cur == 0) {
                res += high * digit;
            }
            else if (cur == 1) {
                res += high * digit + low + 1;
            }
            else {
                res += (high + 1) * digit;
            }
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10; 
        }

        return res;
    }
};




/*
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

 

示例 1：

输入：n = 13
输出：6
示例 2：

输入：n = 0
输出：0
 

提示：

0 <= n <= 2 * 10^9


*/
