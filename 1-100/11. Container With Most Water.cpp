#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int x = min(height[l], height[r]) * (r - l);
            ans = max(ans, x);
            if (height[l] <= height[r]) ++l;
            else --r;
            
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    cout << solution.maxArea({1,2,3,4,5,6,7}) << endl;
    return 0;
}

/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。

输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

提示：

n = height.length
2 <= n <= 3 * 10^4
0 <= height[i] <= 3 * 10^4
*/