/* ************************************************************************
> File Name:     16_findTargetSumWays.cpp
> Author:        xmw01
> Created Time:  Sat 13 May 2023 02:52:27 PM CST
> Description:   
 ************************************************************************/


/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例：

输入：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
一共有5种方法让最终目标和为3。

提示：

数组非空，且长度不会超过 20 。
初始的数组的和不会超过 1000 。
保证返回的最终结果能被 32 位整数存下
*/

/*
如何转化为01背包问题呢。

假设加法的总和为x，那么减法对应的总和就是sum - x。

所以我们要求的是 x - (sum - x) = target

x = (target + sum) / 2

此时问题就转化为，装满容量为x的背包，有几种方法。

这里的x，就是bagSize，也就是我们后面要求的背包容量。


dp[j] 表示：填满j（包括j）这么大容积的包，有dp[j]种方法

只要搞到nums[i]），凑成dp[j]就有dp[j - nums[i]] 种方法。

那么凑整dp[5]有多少方法呢，也就是把 所有的 dp[j - nums[i]] 累加起来。

所以求组合类问题的公式，都是类似这种：
dp[j] += dp[j - nums[i]]
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int target){
        int sum = 0;

        for(int num : nums){
            sum += num;
        }

        // there are no results in the following two situations
        if((target + sum) % 2 == 1) return 0;
        if(abs(target) > sum) return 0;

        //as descripted in the annotations, bagSize is calculated by this formula
        int bagSize = (target + sum)/2;
        
        //dp formula initialization 
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            for(int j = bagSize; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
                //cout << "j: " << j << " " << dp[j] << endl;
            }
        }
        //cout << "bagSize: " << bagSize << endl;
        return dp[bagSize];
        
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int result = solution.findTargetSumWays(nums, target);
    cout << "The answer is: " << result << endl;
}



