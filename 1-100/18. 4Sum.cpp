#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int size=nums.size();
        for(int a=0;a<size-3;++a)
        {
            if(a>0&&nums[a]==nums[a-1])continue;
            for(int b=a+1;b<size-2;++b)
            {
                if(b>a+1&&nums[b]==nums[b-1])continue;
                int i=b+1,j=size-1;
                while(i<j)
                {
                    int sum=nums[a]+nums[b]+nums[i]+nums[j];
                    if(sum<target)
                        while(i<j&&nums[i]==nums[++i]);
                    else if(sum>target)
                        while(i<j&&nums[j]==nums[--j]);
                    else{
                        result.push_back(vector<int>{nums[a],nums[b],nums[i],nums[j]});
                        while(i<j&&nums[i]==nums[++i]);
                        while(i<j&&nums[j]==nums[--j]);
                    }
                }
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    
    return 0;
}


/*给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：答案中不可以包含重复的四元组。

 

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：

输入：nums = [], target = 0
输出：[]
 

提示：

0 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/