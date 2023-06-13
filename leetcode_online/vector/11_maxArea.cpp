/* ************************************************************************
> File Name:     11_maxArea.cpp
> Author:        xmw01
> Created Time:  Tue 13 Jun 2023 02:24:00 PM CST
> Description:   
 ************************************************************************/
/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

https://leetcode.cn/problems/container-with-most-water/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//暴力解法，在数据两巨大情况下会超时
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxValue = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++){
                int validHeight = min(height[i], height[j]);
                maxValue = max(maxValue, (j - i) * validHeight);
            }
        }
        return maxValue;
    }
};

//双指针法，从两端开始的双指针 left/right  不断向里面收缩。

class Solution {
    public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0 && height.size() == 1) return 0;
        int maxValue = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            maxValue = max(maxValue, ((right - left)* min(height[left], height[right])));
            if (height[left] < height[right]) left++;
            else right--;
        }
        return maxValue;
    }
};