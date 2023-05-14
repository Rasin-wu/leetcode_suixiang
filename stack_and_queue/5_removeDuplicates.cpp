/* ************************************************************************
> File Name:     5_removeDuplicates.cpp
> Author:        xmw01
> Created Time:  Sun 14 May 2023 04:00:47 PM CST
> Description:   
 ************************************************************************/

/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

示例：

输入："abbaca"
输出："ca"
解释：例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
提示：

1 <= S.length <= 20000
S 仅由小写英文字母组成。
*/



#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string& s){
        stack<char> st;
        for(char ch : s){
            if(st.empty() || ch != st.top()){
                st.push(ch);
            }else{
                st.pop();
            }
        }
        string result = "";
        // stack traverse
        while (!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

};



int main()
{
    Solution solution;
    string str = "abbaca";
    string result = solution.removeDuplicates(str);
    cout << result << endl;
}






