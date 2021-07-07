#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count_0 = 0;
        int i;
        for (i = 0; i < nums.size(); i++) // 统计0的个数
        {
            if (nums[i] == 0)count_0++;
            else break;
        }

        while(i+1 < nums.size()) // 接着遍历0后面的数
        {
            if(nums[i+1] == nums[i]+1) // 如果是顺子就遍历下一张
                i++;
            else
            {
                if(--count_0 < 0) return false; // count当作万能牌，用一张少一张，当没有万能牌时就不是顺子。
                nums[i] += 1; // 用完一张的效果：将当前的数加一
            }
        }
        
        return true;
    }
};


/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

 

示例 1:

输入: [1,2,3,4,5]
输出: True
 

示例 2:

输入: [0,0,1,2,5]
输出: True
 

限制：

数组长度为 5 

数组的数取值为 [0, 13] .


*/