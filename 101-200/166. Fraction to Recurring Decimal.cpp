#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    using LL = long long;
    string fractionToDecimal(int numerator, int denominator) {
        LL x = numerator, y = denominator;
        if ( x % y == 0 ) return to_string(x / y);
        
        bool is_neg = (x >> 31) ^ (y >> 31);
        if( x < 0 ) x = -x;
        if( y < 0 ) y = -y;
        unordered_map<LL, int> hash;
        string ret;
        if( is_neg ) ret.push_back( '-' );
        ret += to_string(x / y) + '.';
        x %= y;
        while( x ) {
            if ( hash.count( x ) ) {
                ret = ret.substr(0, hash[x]) + '(' + ret.substr(hash[x]) + ')';
                break;
            }
            hash[x] = ret.size();
            x *= 10;
            ret += to_string(x / y);
            x %= y;
        }
        return ret;
    }
};


/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 104 。

 

示例 1：

输入：numerator = 1, denominator = 2
输出："0.5"
示例 2：

输入：numerator = 2, denominator = 1
输出："2"
示例 3：

输入：numerator = 2, denominator = 3
输出："0.(6)"
示例 4：

输入：numerator = 4, denominator = 333
输出："0.(012)"
示例 5：

输入：numerator = 1, denominator = 5
输出："0.2"
 

提示：

-231 <= numerator, denominator <= 231 - 1
denominator != 0



*/