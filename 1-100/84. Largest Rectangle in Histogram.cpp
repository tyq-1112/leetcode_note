#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int left[n] , right[n];
        memset(left,0,sizeof left);
        memset(right,0,sizeof right);

        stack<int> st ;
        for(int i = 0 ; i < n  ; i++){
            //说明此柱子不能向左边扩大
            if(!st.size() || heights[i] > heights[st.top()]) {
                left[i] = i;
            }else {
                //向左能延申
                while(st.size() && heights[st.top()] >= heights[i]) st.pop();
                if(st.size()) left[i] = st.top()+1;
                else left[i] = 0;
            }
            st.push(i) ;
        }
        while(st.size()) st.pop();

        //同理每一根柱子向右能扩大的距离
        for(int i = n-1 ; i >= 0  ; i--){
            if(!st.size() || heights[i] > heights[st.top()]){
                right[i] = i;
            }else{
                while(st.size() && heights[st.top()] >= heights[i]) st.pop();
                if(st.size()) right[i] = st.top()-1;
                else right[i] = n-1;
            }
            st.push(i);
        }
        
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            res = max(res , heights[i]*(right[i] - left[i] + 1));
            //cout<<heights[i] <<"  L: "<<left[i]<<"  R: "<<right[i]<<"  res: "<<res<<endl;
        }
        return res;
    }
};

/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 



以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 



图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 

示例:

输入: [2,1,5,6,2,3]
输出: 10


*/