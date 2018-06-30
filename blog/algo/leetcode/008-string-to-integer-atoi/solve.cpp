#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
class Solution 
{
    /*
     多情况考虑
     字符串前面可以有多个空白字符
     接着是一个可选的'+','-'符号
     然后是一些表示数字的字符
     表示数字的字符之后可以出现一些非数字字符,但是这些字符不影响原计数
     */
public:
   int myAtoi(string str)
   {
       int n = str.length();
       if(n == 0) return 0;
       int i = 0;
       //跳过空格
       while(str[i] == ' ') ++i; 
       //可选符号
       int sign = 1; //默认为正数
       if(str[i] == '-' || str[i] == '+')
       {
           if(str[i] == '-') sign = -1;
           ++i;
       }
       //数值位: 如-456 +456
       double sum = 0.0;
       while(i < n && '0' <= str[i] && str[i] <= '9')
       {
           if(sign == -1)
           {
               sum = sum * 10 + '0' - str[i]; 
               //cout<<"ch:"<<'0'-str[i]<<" sum:"<<sum<<endl;
               //判断溢出:下溢出返回最小值
               if(sum < INT_MIN * 1.0) return INT_MIN;
           }
           else 
           {
               sum = sum * 10 + str[i] - '0'; 
               //判断溢出:上溢出返回最大值
               if(sum > INT_MAX * 1.0) return INT_MAX;
           }
           ++i;
       }
       return  (int)sum;
   }
};
//=======================Driver===========================
int main()
{
    Solution sol;
    //cout<<INT_MAX<<"\t"<<INT_MIN<<endl;
    //cout<<sol.myAtoi("-")<<endl;
    //cout<<sol.myAtoi("+")<<endl;
    //cout<<sol.myAtoi("0")<<endl;
    //cout<<sol.myAtoi("+456")<<endl;
    //cout<<sol.myAtoi("-456")<<endl;
    cout<<sol.myAtoi("2147483648")<<endl; //INT_MAX+1
    cout<<sol.myAtoi("-2147483649")<<endl; //INT_MIN-1
    return 0;
}


/*
===========makefile=================
all:
    @g++  solve.cpp -o   solve
    @./solve
clean:
    rm -f solve
    reset
===========leetcode accepted========
1047 / 1047 test cases passed.
Status: Accepted
Runtime: 19 ms
Submitted: 0 minutes ago
===========submission date=========
2017-01-19 Thu 09:23 PM
*/
