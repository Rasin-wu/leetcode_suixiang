/* ************************************************************************
> File Name:     permute.cpp
> Author:        xmw01
> Created Time:  Thu 11 May 2023 05:35:18 PM CST
> Description:   
 ************************************************************************/

/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出: [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
private:
    vector<vector<int> > result;
    vector<int> path;
    
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }

    }
public:
    vector<vector<int> > permute(vector<int>& nums){
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int> > output;
    output = solution.permute(nums);
    cout << output.size() << endl;
    for (vector<vector<int> >::iterator iter = output.begin(); iter != output.end(); iter++){      //2D vector print
        for(vector<int>::iterator j = iter->begin(); j != iter->end(); j++){             //must use -> for pointer
            cout << *j << " ";
        }
        cout << endl;
    }
}










