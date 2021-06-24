#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
/*
由于n!的后缀0是由起质因子2和质因子5相乘而来的，而2的个数总是比5多的，因此我们只需要计算n!中质因子5的个数即可。
*/
    int trailingZeroes(int n) {
        return n < 5 ? 0 : n/5 + trailingZeroes(n/5); 
    }
};


/*
给定一个整数 n，返回 n! 结果尾数中零的数量。

示例 1:

输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
示例 2:

输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
说明: 你算法的时间复杂度应为 O(log n) 。

*/