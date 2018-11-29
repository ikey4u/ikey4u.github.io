#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
class Solution 
{
public:
  bool isPalindrome(int x) 
  {
      //负数不是回文
      if(x < 0) return false;
      //最左边,最右边的数位编号
      int left = 1,right = floor(log10(x * 1.0)) + 1;
      //取最左边的数位因子:
      //1==>10^0 2==>10^1 3==>10^2 len==>10^(len-1)
      //int head = pow(10,right - 1);
      int head = 1;
      for(int i = 1; i < right; ++i) head *= 10;
      //回文检测
      while(left <= right) 
      {   
          int l = x / head;
          int r = x % 10;
          if(l != r) return false;
          ++left;
          --right;
          x = x - l * head;
          x = (x - r) / 10;
          head /= 100;
      }
      return true;
  }
};
//=======================Driver===========================
int main()
{
    Solution sol;
    cout<<sol.isPalindrome(-1)<<endl;
    cout<<sol.isPalindrome(1)<<endl;
    cout<<sol.isPalindrome(10)<<endl;
    cout<<sol.isPalindrome(121)<<endl;
    cout<<sol.isPalindrome(INT_MAX)<<endl;
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
11507 / 11507 test cases passed.
Status: Accepted
Runtime: 185 ms
Submitted: 0 minutes ago
===========submission date=========
2017-02-03 Fri 10:51 AM
*/
