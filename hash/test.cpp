/* ************************************************************************
> File Name:     test.cpp
> Author:        xmw01
> Created Time:  Sun 14 May 2023 10:21:04 AM CST
> Description:   
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{
    vector<int> orign = {1,1,3,4,5,5,5,3,8,8,8,7};
    set<int> output(orign.begin(), orign.end());
    // set traverse
    for(auto it = output.begin(); it != output.end(); it++){
        cout << *it << endl;
    }

    vector<int> output_vector(output.begin(), output.end());
    for(int num : output_vector){
        cout << num << endl;
    }

}

