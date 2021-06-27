#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() , ans = INT_MAX;
        ll sum[n+1];
        memset(sum,0,sizeof sum);
        for(int i =1 ; i<=n ; i++)sum[i] = sum[i-1]+nums[i-1];
        if(sum[n] < target) return 0;
        
        int j = 1;
        for(int i = 1 ; i <= n ; ){
            if(sum[i] - sum[j-1] >= target) {
                ans = min(ans , i-j+1);
                j++;
            }else i++;
        }

        return ans;
    }
};




/*
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 

提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
 

进阶：

如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

*/