/* ************************************************************************
> File Name:     41_findFirstMissingPossive.cpp
> Author:        xmw01
> Created Time:  Tue 13 Jun 2023 06:37:07 PM CST
> Description:   
 ************************************************************************/

/*
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

输入：nums = [3,4,-1,1]
输出：2

https://leetcode.cn/problems/first-missing-positive/
*/

//暴力解法
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int begin = 1;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) continue;
            if (nums[i] == pre) continue;
            if (nums[i] != begin) return begin;
            begin++;
            pre = nums[i];
        }
        return begin;
    }
};

class Solution{
public:
    //原地哈希做法
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1){
                //cout << i << endl;
                if(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                    swap(nums[i], nums[nums[i] - 1]);    
                }
                else break;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) return i + 1;
        }
        return nums.size() + 1;
    }
};