#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> height) {
        stack<int> st;
        int i = 0 , ans = 0;
        while(i < height.size()){
            while(st.size() && height[st.top()] <= height[i]){
                int pre = st.top();
                st.pop();
                if(!st.size()) break;
                int wid = (i - st.top() - 1);
                int hig = min(height[i] , height[st.top()] ) - height[pre];
                ans+=wid*hig;
            }
            st.push(i++);
        }
        return ans;
    }
};



int main()
{
    Solution solution;
    cout << solution.trap({0,1,0,2,1,0,1,3,2,1,2,1}) << endl;
    return 0;
}

/*

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。


示例 1：


输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9


提示：

n == height.length
0 <= n <= 3 * 10^4
0 <= height[i] <= 10^5



*/