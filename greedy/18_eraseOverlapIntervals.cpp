/* ************************************************************************
> File Name:     eraseOverlapIntervals.cpp
> Author:        xmw01
> Created Time:  Fri 12 May 2023 03:58:49 PM CST
> Description:   
 ************************************************************************/

/*
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意: 可以认为区间的终点总是大于它的起点。 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int> >& nums){
        if(nums.size() == 1) return 1;
        //in reverse order by right endpoint
        sort(nums.begin(), nums.end(), cmp);
        int count = 1;
        int end =  nums[0][1];
        //Find the number of interval that doesn't overlap
        for (int i = 1; i < nums.size(); i++){
            if(end <= nums[i][0]){
                count++;
                end = nums[i][1];
            }
        }
        int nums_min = nums.size() - count;
        return nums_min;
    }
};

int main()
{
    vector<vector<int> > nums = {{1, 2},{1, 2},{1, 3}};
    Solution solution;
    int output;
    output  = solution.eraseOverlapIntervals(nums);
    cout << "The answer is: " << output << endl;
}


