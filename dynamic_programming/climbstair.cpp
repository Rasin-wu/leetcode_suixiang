/* ************************************************************************
> File Name:     climbstair.cpp
> Author:        xmw01
> Created Time:  Fri 12 May 2023 08:19:59 PM CST
> Description:   
 ************************************************************************/

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1 阶 + 1 阶
2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1 阶 + 1 阶 + 1 阶
1 阶 + 2 阶
2 阶 + 1 阶
*/

/*
首先是dp[i - 1]，上i-1层楼梯，有dp[i - 1]种方法，那么再一步跳一个台阶不就是dp[i]了么。

还有就是dp[i - 2]，上i-2层楼梯，有dp[i - 2]种方法，那么再一步跳两个台阶不就是dp[i]了么
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int climbStair(int num){
        if(num < 1) return num;
        vector<int> dp(num + 1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= num; i++){
            dp[i] = dp[i -1 ] + dp[i - 2];

        }
        return dp[num];
    }
};


int main()
{

}
