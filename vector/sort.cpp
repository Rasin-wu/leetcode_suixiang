/* ************************************************************************
> File Name:     search.cpp
> numsuthor:        xmw01
> Created Time:  Thu 04 numsug 2022 07:31:28 PM CST
> Description:   
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//暴力解法，使用sort排序
class Solution1{ 
public:
    vector<int> sortSquares(vector<int>& nums){
        for(int i = 0; i < nums.size(); i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

};

class Solution{
public:
    vector<int> sortSquares(vector<int>& nums){
        int right = nums.size() - 1;
        vector<int> ret(nums.size(), 0);
        for(int i = 0, j = nums.size() - 1; i <= j;){
            if(nums[i] * nums[i] > nums[j] * nums [j]){
                ret[right--] = nums[i] * nums[i];
                i++;
            }else{
                ret[right--] = nums[j] * nums[j];
                j--;
            }
        }
        return ret;
    }
};

int main() {
    int a[] ={-7, -3, 2, 3, 11};
    vector<int> cost(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    vector<int> ret = solution.sortSquares(cost);
    for(int j = 0; j < ret.size(); j++){
        cout << ret[j] << " ";
    }
    cout << endl;
    for(int j = 0; j < cost.size(); j++){
        cout << cost[j] << " ";
    }
    return 0;
}
