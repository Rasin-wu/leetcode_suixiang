/* ************************************************************************
> File Name:     canJump.cpp
> Author:        xmw01
> Created Time:  Fri 12 May 2023 10:35:53 AM CST
> Description:   
 ************************************************************************/

/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums){
        int cover = 0;
        if(nums.size() == 1) return true;
        for(int i = 0; i <= cover; i++){
            cover = max(nums[i] + i, cover);
            if(cover >= nums.size() + 1){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {2,3,1,1,4};
    Solution solution;
    bool output;
    output  = solution.canJump(nums);
    cout << "The answer is: " << output << endl;
}




