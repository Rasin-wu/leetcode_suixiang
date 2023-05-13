/* ************************************************************************
> File Name:     2_isAnagram.cpp
> Author:        xmw01
> Created Time:  Sat 13 May 2023 09:31:47 PM CST
> Description:   
 ************************************************************************/

/*

 给定两个字符s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

 示例 1: 输入: s = "anagram", t = "nagaram" 输出: true
 
 示例 2: 输入: s = "rat", t = "car" 输出: false
 
 说明: 你可以假设字符串只包含小写字母。
 
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Soluton
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> record(26, 0);
        for(int i = 0; i <= s.size(); i++){
            record[s[i] - 'a']++;
        }
        for(int i = 0; i <= t.size(); i++){
            record[s[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(record[i] != 0){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s = "anagram";
    string t = "nagaram";

    Soluton solution;
   
    bool result = solution.isAnagram(s, t);
    cout << result << endl;
}
