#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;

    double myPow(double x, int n) {
        int f = 0;
        if(n<0) f = 1;
        double res = 1.0;
        for(ll k = abs(ll(n)) ; k ; k>>=1){
            if(k&1) res *= x;
            x = x*x;
        }
        if(f) res = 1/res;
        return res;
    }
};

int main()
{
    Solution solution;
    cout << solution.myPow(2.0,10) << endl;
    return 0;
}

/*

实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。

 

示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
 

提示：

-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
-10^4 <= x^n <= 10^4


*/