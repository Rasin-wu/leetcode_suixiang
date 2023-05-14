/* ************************************************************************
> File Name:     2_reverseString.cpp
> Author:        xmw01
> Created Time:  Sun 14 May 2023 12:49:35 PM CST
> Description:   
 ************************************************************************/

/*
给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。

如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char>& s, int k){
        for(int i = 0; i < s.size(); i += 2 * k){
            if((i + k) < s.size()){
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else{
                reverse(s.begin() + i, s.end());
            }
        }
    }
    
};


int main()
{
    vector<char> str = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    Solution solution;
    int k = 2;
    solution.reverseString(str, k);
    for(char ch : str){
        cout << ch << endl;
    }
}
