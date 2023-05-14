/* ************************************************************************
> File Name:     8_threeSum.cpp
> Author:        xmw01
> Created Time:  Sun 14 May 2023 11:14:57 AM CST
> Description:   
 ************************************************************************/

/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意： 答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]]]]]
*/


/*
之前想的 先用转set 再转 vector 的方式来去重，但是最终的结果还是会有重复
*/

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int>& nums){
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                return result;
            }
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while(right > left){
                if(nums[i] + nums[left] + nums[right] > 0) right--;
                else if(nums[i] + nums[left] + nums[right] < 0) left++;
                else{
                    result.push_back(vector<int>({nums[i], nums[left], nums[right]}));

                    // deduplication logic for b and c
                    while(right > left && nums[right] == nums[right - 1]) right--;
                    while(right > left && nums[left] == nums[left + 1]) left++;

                    //when result is found, both right and left contract simultaneously
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};









