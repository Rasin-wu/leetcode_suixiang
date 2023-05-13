/* ************************************************************************
> File Name:     fib.cpp
> Author:        xmw01
> Created Time:  Fri 12 May 2023 05:26:59 PM CST
> Description:   
 ************************************************************************/

/*
斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是： F(0) = 0，F(1) = 1 F(n) = F(n - 1) + F(n - 2)，其中 n > 1 给你n ，请计算 F(n) 。

示例 1：

输入：2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1
示例 2：

输入：3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2
示例 3：

输入：4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3
提示：

0 <= n <= 30
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int fib(int num){
        if(num == 1) return 1;
        vector<int> dp(num + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i < (num + 1); i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[num];
    }
};

int main()
{
    int num = 3;
    Solution solution;
    int output = solution.fib(num);
    cout << "The answer is: " << output << endl;
}



