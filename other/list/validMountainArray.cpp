/* ************************************************************************
> File Name:     validMountainArray.cpp
> Author:        xmw01
> Created Time:  Tue 06 Jun 2023 07:30:47 PM CST
> Description:   
 ************************************************************************/

/*
给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

arr.length >= 3
在 0 < i < arr.length - 1 条件下，存在 i 使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int left = 0;
        int right = nums.size() - 1;
        while (nums[left + 1] > nums[left] && left < (nums.size() - 1)) {
            left++;
        }
        while (nums[right - 1] > nums[right] && right > 0) {
            right--;
        }
        cout << left << "   " << right << endl;
        if (left == right) return true;
        else return false;
    }
};

int main() {
    vector<int> nums = {0,3,2,1};
    Solution solution;
    //vector<int> result;
    bool result = solution.validMountainArray(nums);
    cout << result << endl;
}
