#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int r1, r2, c1 = 0, c2 = 0;

        //任何消耗以减物品需要两件不同的物品陪葬，
        for (auto x: nums)
            if (c1 && x == r1) c1 ++ ;
            else if (c2 && x == r2) c2 ++ ;
            else if (!c1) r1 = x, c1 ++ ;
            else if (!c2) r2 = x, c2 ++ ;
            else c1 --, c2 -- ;

        c1 = 0, c2 = 0;
        for (auto x: nums)
            if (x == r1) c1 ++ ;
            else if (x == r2) c2 ++ ;

        vector<int> res;
        int n = nums.size();
        if (c1 > n / 3) res.push_back(r1);
        if (c2 > n / 3) res.push_back(r2);
        return res;
    }
};



/*

给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

 

示例 1：

输入：[3,2,3]
输出：[3]
示例 2：

输入：nums = [1]
输出：[1]
示例 3：

输入：[1,1,1,3,3,2,2,2]
输出：[1,2]
 

提示：

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109


*/
