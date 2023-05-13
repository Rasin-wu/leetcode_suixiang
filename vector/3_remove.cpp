/* ************************************************************************
> File Name:     search.cpp
> Author:        xmw01
> Created Time:  Thu 04 Aug 2022 07:31:28 PM CST
> Description:   
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//快慢指针法
class Solution1{ 
public:
    int removeElement(vector<int>& nums, int val){
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if(val != nums[fastIndex]){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

//暴力双循环
class Solution{ 
public:
    int removeElement(vector<int>& nums, int val){
        int size = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(val == nums[i]){
                for(int j = i; j < nums.size() - 1; j++){
                    nums[j] = nums[j + 1];   
                }
                i--;
                size--;
            }
        }
        return size;
    }
};

int main() {
    int a[] ={0, 2, 2, 3, 5, 9, 12};
    int target = 2;
    vector<int> cost(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    cout << solution.removeElement(cost, 2) << endl;
    return 0;
}
