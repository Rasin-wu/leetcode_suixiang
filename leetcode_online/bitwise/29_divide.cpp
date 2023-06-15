/* ************************************************************************
> File Name:     29_divide.cpp
> Author:        xmw01
> Created Time:  Thu 15 Jun 2023 09:56:12 AM CST
> Description:   
 ************************************************************************/
/*
给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。

整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ，-2.7335 将被截断至 -2 。

返回被除数 dividend 除以除数 divisor 得到的 商 。

注意：假设我们的环境只能存储 32 位 有符号整数，其数值范围是 [−231,  231 − 1] 。本题中，如果商 严格大于 231 − 1 ，则返回 231 − 1 ；如果商 严格小于 -231 ，则返回 -231 。

https://leetcode.cn/problems/divide-two-integers/
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        //极端点的边界情况，用abs会有越界问题，需要提前输出判断；
        if (dividend == INT32_MIN) {       
            if (divisor == 1) return INT32_MIN;
            else if (divisor == -1) return INT32_MAX;
        }
        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }

        bool neg;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 &&  divisor > 0)) neg = true;
        else neg = false;
        long absDividend = abs(dividend);
        long absDivisor = abs(divisor);
        long cntSum = 0;
        while (absDividend >= absDivisor) {
            long cnt = 0;
            long tmpDivisor = absDivisor;
            while (absDividend >= (tmpDivisor<<1)) {
                tmpDivisor<<=1;
                cnt++;
            }
            //cout << cnt;
            absDividend -= tmpDivisor;
            cntSum += (1<<cnt);
        }
        if (neg) cntSum = -cntSum;
        if (cntSum > INT32_MAX) {
            return INT32_MAX;
        }
        if (cntSum <= INT32_MIN) return INT32_MIN;
        return cntSum;
    }
};