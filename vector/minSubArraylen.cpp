/* ************************************************************************
> File Name:     search.cpp
> Author:        xmw01
> Created Time:  Thu 04 Aug 2022 07:31:28 PM CST
> Description:   
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//暴力解法
class Solution1{ 
public:
    int minSubArrayLen(vector<int>& nums, int s){
        int ret = INT32_MAX;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                if(sum >= s){
                    int minLen = j - i + 1;
                    ret = ret < minLen ? ret : minLen;
                    break;
                }
            }
            sum = 0;
        }
        if(ret == INT32_MAX){
            return 0;
        }else{
            return ret;
        }
    }

};

//滑动窗口
class Solution{
public:
    int minSubArrayLen(vector<int>& nums, int s){
        int ret = INT32_MAX;
        int sum = 0;
        int left = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= s){
                int len = i - left + 1;
                ret = ret < len ? ret : len;
                sum -= nums[left];
                left++;
            }
        }
        if(ret == INT32_MAX){
            return 0;
        }else{
            return ret;
        }
    }
};

int main() {
    int a[] ={2, 3, 1, 2, 4, 3};
    int sum = 7;
    vector<int> cost(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    cout << solution.minSubArrayLen(cost, sum) << endl;
    return 0;
}
