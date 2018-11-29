#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
class Solution 
{
public:
   int reverse(int x) 
   {
       /* INT_MAX=2147483647	INT_MIN=-2147483648 */
       //x在使用log10时不能为0
       if(x == 0) return 0;
       //符号位
       int sign = x < 0 ? -1 : 1;
       //取x的绝对值:可能溢出
       if(x * 1.0 * sign > INT_MAX) return 0;
       x = x * sign;
       //求位数:p进制整数k的位数为:floor(log_p(k))+1
       //可用用换底公式求:log_p(k)=log10(k)/log10(p)
       int k = log10(x * 1.0) + 1; 
       double rx = 0 ;
       for(int i = k - 1;i >= 0; --i)
       {
           //溢出判断
           if(rx > INT_MAX) return 0;
           int d = x % 10;
           x = (x - d) / 10;
           rx += d * pow(10,i);
       }
       return sign * (int)(rx);
   }
};
//=======================Driver===========================
int main()
{
    Solution sol;
    //cout<<INT_MAX<<"\t"<<INT_MIN<<endl;
    //cout<<sol.reverse(0)<<endl;
    cout<<sol.reverse(-2147483648)<<endl;
    return 0;
}


/*
===========complexity==============
Time Complexity:O(1) 
Space Complexity:O(1)
===========makefile=================
all:
    @g++  solve.cpp -o   solve
    @./solve
clean:
    rm -f solve
    reset
===========leetcode accepted========
1032 / 1032 test cases passed.
Status: Accepted
Runtime: 9 ms
Submitted: 0 minutes ago
===========submission date=========
2017-01-15 Sun 11:25 PM
*/
