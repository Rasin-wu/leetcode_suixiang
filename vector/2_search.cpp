/* ************************************************************************
> File Name:     search.cpp
> Author:        xmw01
> Created Time:  Thu 04 Aug 2022 07:31:28 PM CST
> Description:   
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int middle = left + (right - left)/2;
            if(nums[middle] < target){
                right = middle - 1;
            }else if(nums[middle] > target){
                left = middle + 1;
            }else return middle;
        }
        return -1;
    }

};

int main() {
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    int target = 3;
    //vector<int> cost(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    int result;
    result = solution.search(a, target);

    cout << result << endl;

}
