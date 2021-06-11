#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> nums, int target) {
        
        if(!nums.size()) return {-1,-1};
        int  l = 0 , r = nums.size() -1 ;
        while(l < r){
            int mid = l +  r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid+1;
        }
        int L = r;
        if(nums[r] != target) return {-1,-1};

        l = 0 , r = nums.size() -1 ;
        while(l < r){
            int mid = l+r+1>>1;
            if(nums[mid] <= target) l = mid;
            else r = mid-1;
        }
        return {L,r};
    }
};


int main()
{
    Solution solution;
    auto t = solution.searchRange({1,2,3,3,4,5,6},3);
    cout << t[0] <<" "<< t[1] << endl;
    return 0;
}

/*

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 

提示：

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums 是一个非递减数组
-10^9 <= target <= 10^9




*/