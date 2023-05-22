/* ************************************************************************
> File Name:     phone_num_combination.cpp
> Author:        xmw01
> Created Time:  Thu 27 Apr 2023 07:56:38 PM CST
> Description:   
 ************************************************************************/

/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index) {
        if(index == digits.size()){
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0'; //converts the number pointed to by index to int
        string letters = letterMap[digit]; // takes the character set corresponding to the number
        for (int i = 0; i < letters.size(); i++){
            s.push_back(letters[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombination(string digits){
        s.clear();
        result.clear();
        if(digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }

};

int main() {
    Solution solution;
    string input = "2334";
    vector<string> output;
    output = solution.letterCombination(input);
    cout << output.size() << endl;
    for(vector<string>::iterator iter = output.begin(); iter != output.end(); iter++){ // result print
        cout << *iter << " ";
    }
    cout << endl;
}