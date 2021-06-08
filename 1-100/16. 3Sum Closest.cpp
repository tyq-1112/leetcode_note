#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin() , nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.size();i++) {
            int start = i+1, end = nums.size() - 1;
            while(start < end) {
                int sum = nums[start] + nums[end] + nums[i];
                if(abs(target - sum) < abs(target - ans)) ans = sum;
                if(sum > target) end--;
                else if(sum < target) start++;
                else
                    return ans;
            }
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    cout << solution.threeSumClosest({-1,2,1,-4},1) << endl;
    return 0;
}
/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。


提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4


*/