/* ************************************************************************
> File Name:     84_largestRectangleArea.cpp
> Author:        xmw01
> Created Time:  Wed 14 Jun 2023 04:22:27 PM CST
> Description:   
 ************************************************************************/

/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
https://leetcode.cn/problems/largest-rectangle-in-histogram/
*/

#include <iostream>
#include <vector>

using namespace std;

// 暴力解法
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        if (heights.size() == 0) return largestArea;
        for (int i = 0; i < heights.size(); i++) {
            int left = i, right = i;
            int w = 1;
            while (--left >= 0 && heights[left] >= heights[i]) w++;
            while (++right < heights.size() && heights[right] >= heights[i]) w++;
            //cout << left << " " << right << endl;
            largestArea = max(largestArea, (w) * heights[i]); 
            //cout << largestArea << endl;
        } 
        return largestArea;

    }
};

//利用单调栈来做
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       vector<int> pre_heights = heights;
       pre_heights.insert(pre_heights.begin(), 0);  //增加左右的0方便后面计算
       pre_heights.push_back(0);
       stack<int> st;   //栈
       int largestArea = 0;
       for (int i  = 0; i < pre_heights.size(); i++) {
           //使用单调栈做遍历，站内单调递增顺序
           while (!st.empty() && pre_heights[st.top()] > pre_heights[i]) {
               int h = pre_heights[st.top()];
               st.pop();
               int left = st.top(), right = i;
               largestArea = max(largestArea, (h * (right - left - 1)));
           }
           st.push(i);
       }
       return largestArea;

    }
};