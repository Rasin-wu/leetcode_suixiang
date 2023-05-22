/* ************************************************************************
> File Name:     isPalindrome.cpp
> Author:        xmw01
> Created Time:  Thu 11 May 2023 09:38:06 AM CST
> Description:   
 ************************************************************************/

/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例: 输入: "aab" 输出: [ ["aa","b"], ["a","a","b"] ]
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
private:
    vector<vector<string> > result;
    vector<string> path;
    void backtracking(string& s, int startIndex){
        //if the staring position is larger than s, a partiont scheme has been find
        if(startIndex >= s.size()){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            //it's palindrom, next
            if(isPalindrome(s, startIndex, i)){
                string tmp = s.substr(startIndex, i - startIndex + 1);
                path.push_back(tmp);
            }else{
                //not palindrom, skip it
                continue;
            }
            backtracking(s, i + 1);   //backtracking
            path.pop_back();
        }
    }
public:
    bool isPalindrome(string& s, int begin, int end){
        for(int i = begin, j = end; i < j; i++, j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string> > palindrom_partion(string& s, int startIndex){
        cout << s << endl;
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
    
};

int main()
{
    Solution solution;
    string s ("aab");
    vector<vector<string> > output;
    output = solution.palindrom_partion(s, 0);
    cout << output.size() << endl;
    for (vector<vector<string> >::iterator iter = output.begin(); iter != output.end(); iter++){
        for(vector<string>::iterator j = iter->begin(); j != iter->end(); j++){
            // must use "->" for pointer
            cout << *j << " ";
        }
        cout << endl;
    }
}









