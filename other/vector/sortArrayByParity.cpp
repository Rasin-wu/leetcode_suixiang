/* ************************************************************************
> File Name:     sortArrayByParity.cpp
> Author:        xmw01
> Created Time:  Thu 08 Jun 2023 03:27:12 PM CST
> Description:   
 ************************************************************************/

/*
给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortArrayByParity(vector<int>& nums) {
        int odd = 1;
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] % 2 != 0) {
                while (nums[odd] % 2 != 0) odd += 2;
                swap(nums[i], nums[odd]);
            }
        }
    }
};

int main() {
    vector<int> nums = {4,2,5,7};
    Solution solution;
    solution.sortArrayByParity(nums);
    for (auto item : nums) cout << item << " ";
    cout << endl;
}