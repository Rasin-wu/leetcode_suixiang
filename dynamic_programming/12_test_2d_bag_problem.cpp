/* ************************************************************************
> File Name:     test_2d_bag_problem.cpp
> Author:        xmw01
> Created Time:  Sat 13 May 2023 09:25:03 AM CST
> Description:   
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

void test_2d_bag_problem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    //2d -dynamic array
    vector<vector<int> > dp(weight.size(), vector<int>(bagweight + 1, 0));

    //initialization
    for(int j = weight[0]; j < bagweight; j++){
        dp[0][j] = value[0];
    }

    //start traversing from the item first
    for(int i = 1; i < weight.size(); i++){  //遍历物品
        for(int j = 0; j <= bagweight; j++){  //遍历背包容量
            if(j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            cout << dp[i][j] << endl;
        }
    }
    cout << dp[weight.size() - 1][bagweight] << endl;
}



int main()
{
    test_2d_bag_problem();
}
