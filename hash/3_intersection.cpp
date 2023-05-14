/* ************************************************************************
> File Name:     3_intersection.cpp
> Author:        xmw01
> Created Time:  Sat 13 May 2023 10:09:04 PM CST
> Description:   
 ************************************************************************/

/*
题意：给定两个数组，编写一个函数来计算它们的交集。
说明： 输出结果中的每个元素一定是唯一的。 我们可以不考虑输出结果的顺序。
*/

#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> result_set;
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        for(int num : nums2){
            //搜寻 nums2元素，在num_set中出现过
            if(num_set.find(num) != num_set.end()){
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};


int main()
{
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    Solution solution;
    vector<int> result = solution.intersection(nums1, nums2);
    cout << result.size() << endl;
    for (int num : result){
        cout << num << " ";
    }
    cout << endl;
    
}





