#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;
    double myPow(double x, int _n) {
        ll n = _n;
        int f = 0;
        if(n<0) {
            n = abs(n);
            f = 1;
        }

        if(f) return 1.0/pow(x , n) ;
        else return pow(x,n);
    }

    double pow(double x , ll p){
        double res = 1.0;
        while(p){
            if(p&1) res = res*x;
            x = x*x*1.0;
            p = p>>1;
        }
        return res;
    }
};


/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

 

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
-231 <= n <= 231-1
-104 <= xn <= 104

*/
