#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;

    bool isHappy(int _n) {
        ll n = _n;
        unordered_map<int,int> mp;
        while(1){
            ll tp = n , res = 0;
            while(tp){
                res+=pow(tp%10,2);
                tp = tp/10;
            }
            n = res;
            if(n == 1) return true;
            if(mp[n] == 1) return false;
            mp[n] = 1;
            
        }
        return false;
    }
};


/*

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 true ；不是，则返回 false 。

 

示例 1：

输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
示例 2：

输入：n = 2
输出：false
 

提示：

1 <= n <= 231 - 1
*/