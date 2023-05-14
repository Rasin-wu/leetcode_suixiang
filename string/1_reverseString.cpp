/* ************************************************************************
> File Name:     1_reverseString.cpp
> Author:        xmw01
> Created Time:  Sun 14 May 2023 12:49:35 PM CST
> Description:   
 ************************************************************************/

/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

示例 1：
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]

示例 2：
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]""""""""""""]""""""""""""]""""""""""]""""""""""])]
*/


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char>& s){
        for(int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--){
            swap(s[i], s[j]);

        }
    }
    
};


int main()
{
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    Solution solution;
    solution.reverseString(str);
    for(char ch : str){
        cout << ch << endl;
    }
}
