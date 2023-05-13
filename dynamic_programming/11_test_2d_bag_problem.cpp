/* ************************************************************************
> File Name:     test1d_bag_problem.cpp
> Author:        xmw01
> Created Time:  Sat 13 May 2023 11:03:03 AM CST
> Description:   
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

void test_1d_bag_problem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    //1d -dynamic array
    //initialization
    vector<int> dp(bagweight + 1, 0);

    //start traversing from the item first
    for(int i = 0; i < weight.size(); i++){  //遍历物品   务必注意，这个是从0开始的，因为1没有初始化，和二维数组的dp算法不一样
        for(int j = bagweight; j >= weight[i]; j--){  //遍历背包容量    
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            cout << dp[j] << endl;
        }
    }
    cout << dp[bagweight] << endl;
}



int main()
{
    test_1d_bag_problem();
}
