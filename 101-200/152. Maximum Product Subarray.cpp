#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0] , f = nums[0] , g = nums[0];
        /*
        f[i]表示所有从0到i并且选用nums[i]获得的最大乘积
        g[i]表示所有从0到i并且选用nums[i]获得的最小乘积
        1、
        当nums[i] >= 0时，f[i] = max(nums[i], f[i - 1] * nums[i])
        当nums[i] < 0时，f[i] = max(nums[i], g[i - 1] * nums[i])

        2、
        当nums[i] >= 0时，g[i] = min(nums[i], g[i - 1] * nums[i])
        当nums[i] < 0时，g[i] = min(nums[i], f[i - 1] * nums[i])

        可以通过用滚动数组的方式，记录 f = f[i - 1]， g = g[i - 1]
        */

        for(int i = 1 ; i < nums.size() ; i++){
            int pref = f , preg = g;
            if(nums[i] > 0) {
                f = max(nums[i] , f * nums[i]);
                g = min(nums[i] , g * nums[i]);
            }else{
                f = max(nums[i] , preg * nums[i]);
                g = min(nums[i] , pref * nums[i]);
            }
            ans = max(ans , f);
        }
        return ans;
    }
};

/*
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。


*/