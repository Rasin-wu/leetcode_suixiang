/* ************************************************************************
> File Name:     moveZeroes.cpp
> Author:        xmw01
> Created Time:  Thu 08 Jun 2023 10:32:35 AM CST
> Description:   
 ************************************************************************/

/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12] 输出: [1,3,12,0,0] 说明:

必须在原数组上操作，不能拷贝额外的数组。 尽量减少操作次数。
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (!nums.size()) return;
        int slow = 0;
        int fast = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[slow] = nums[fast];
                slow++; fast++;
            }
            else {
                fast++;
            }
        }
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution solution;
    solution.moveZeroes(nums);
    for (auto item : nums) {
        cout << item << " ";
    }
    cout << endl;
}