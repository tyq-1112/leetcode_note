#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int len = m + n;
        int left = -1, right = -1;
        int aStart = 0, bStart = 0;
        for (int i = 0; i <= len / 2; i++) {
            left = right;
            if (aStart < m && (bStart >= n || nums1[aStart] < nums2[bStart])) {
                right = nums1[aStart++];
            } else {
                right = nums2[bStart++];
            }
        }
        if ((len & 1) == 0)return (left + right) / 2.0;
        else return right;
    }
};

int main()
{
    Solution solution;
    cout<< solution.findMedianSortedArrays({1,2,3},{4}) << endl;
    return 0;
}

/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出并返回这两个正序数组的 中位数 。

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6

*/