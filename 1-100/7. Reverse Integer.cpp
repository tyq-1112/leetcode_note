#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            //INT_MAX = 2^31-1，INT_MIN= -2^31
            //再次进来必超范围
            if (res < INT_MIN / 10 || res > INT_MAX / 10) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

// int main()
// {
//     Solution solution;
//     cout<< solution.reverse(-123) << endl;
//     return 0;
// }

/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。

示例 1：

输入：x = 123
输出：321

示例 2：

输入：x = -123
输出：-321

示例 3：

输入：x = 120
输出：21

-231 <= x <= 231 - 1
*/