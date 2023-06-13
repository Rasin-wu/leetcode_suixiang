/* ************************************************************************
> File Name:     4_findMedianSortedArray.cpp
> Author:        xmw01
> Created Time:  Tue 13 Jun 2023 10:33:12 AM CST
> Description:   
 ************************************************************************/

/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
*/

#include <iostream>
#include <vector>

using namespace std;

//如何把时间复杂度降低到O(log(m+n)) 呢？如果对时间复杂度的要求有这个要求通常都需要用到二分查找，这道题也可以通过二分查找实现。


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        double result = 0;
        if (nums1.size() == 0 && nums2.size() == 0) {
            return result;
        } else if (nums1.size() == 0) {
            if (len%2 == 1) return nums2[len/2];
            else return (double(nums2[len/2]) + double(nums2[len/2 - 1]))/2;
        }else if (nums2.size() == 0) {
            if (len%2 == 1) return nums1[len/2];
            else return (double(nums1[len/2]) + double(nums1[len/2 - 1]))/2;
        }
        if (len%2 == 1){
           int k = len/2 + 1; 
           result = findIndexValue(nums1, nums2, k);
        } else {
            int k = len/2;
            result = (double(findIndexValue(nums1, nums2, k)) + double(findIndexValue(nums1, nums2, (k + 1))))/2;
        }
        return result;
    }       
    int findIndexValue(vector<int>&nums1, vector<int>& nums2, int k) {
        //std::cout << k << endl;
        int start1 = -1, start2 = -1;
        //std::cout << start1 << " " << start2 << endl;
        int step = k;
        double result;
        while (true) {
            //std::cout << start1 << " " << start2 << endl;
            step = step/2 > 0 ? step/2 : 1;
            //std::cout << k << endl;
            start1 = (start1 + step) < nums1.size() ? start1 + step : nums1.size() - 1;
            start2 = (start2 + step) < nums2.size() ? start2 + step : nums2.size() - 1;
            //std::cout << start1 << " " << start2 << endl;

            if (nums1[start1] < nums2[start2]) {
                result = nums1[start1]; 
                start2 = start2 - step > -1 ? start2 - step : -1;
                if ((start1 + start2) >= (k - 2)) {
                    //std::cout << start1 << start2 << endl;
                    return result;
                }
                //cout << k-start1-2 << endl;
                if (start1 == nums1.size() - 1) return nums2[k - start1 - 2];
            } else {  
                result = nums2[start2];
                start1 = start1 - step > -1 ? start1 - step : -1;
                if ((start1 + start2) >= (k - 2)) return result;
                if (start2 == nums2.size() - 1) return nums1[k - start2 - 2];
            }
        }
        return result;
    }

};