/* ************************************************************************
> File Name:     3_isValid.cpp
> Author:        xmw01
> Created Time:  Sun 14 May 2023 03:39:12 PM CST
> Description:   
 ************************************************************************/

/*
给定一个只包括 '('，')'，'{
'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{
}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{
[]}"
输出: true"]
*/


#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s){
        if(s.size()%2 != 0){
            return false;
        }

        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(')');
            else if(s[i] == '{') st.push('}');
            else if(s[i] == '[') st.push(']');
            //第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            //第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if(st.empty() || st.top() != s[i]) return false;
            else st.pop();   // st.top() 与 s[i] 相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return st.empty();
    }

};


int main()
{
    Solution solution;
    string str = "([)]";
    bool result = solution.isValid(str);
    cout << result << endl;
}



