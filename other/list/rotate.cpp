/* ************************************************************************
> File Name:     rotate.cpp
> Author:        xmw01
> Created Time:  Thu 08 Jun 2023 11:13:10 AM CST
> Description:   
 ************************************************************************/

/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

进阶：

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？

示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释: 向右旋转 1 步: [7,1,2,3,4,5,6]。 向右旋转 2 步: [6,7,1,2,3,4,5]。 向右旋转 3 步: [5,6,7,1,2,3,4]。
示例 2:

输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 向右旋转 1 步: [99,-1,-100,3]。 向右旋转 2 步: [3,99,-1,-100]。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k  = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    Solution solution;
    solution.rotate(nums, 3);
    for (auto item : nums) {
        cout << item << " ";
    }
    cout << endl;
}