#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0] , cnt = 1;
        for(auto x : nums){
            if(ele == x) cnt++;
            else cnt--;
            if(cnt == 0){
                ele = x;
                cnt = 1;
            }
        }
        return ele;
    }
};


/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

 

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
 

限制：

1 <= 数组长度 <= 50000

 

*/
