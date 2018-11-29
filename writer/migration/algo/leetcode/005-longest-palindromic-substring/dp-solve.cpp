#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        //动态申请空间
        char **dp = new char*[n]; 
        for(int i = 0;i < n; ++i) 
        {
            dp[i] = new char[n];
            memset(dp[i],'1',sizeof(char) * n);
        }
        //记录要返回的回文串的:开始索引,结束索引,长度
        int beg = 0,end = 0,len = 1;
        //由于是计算dp[i+1][j-1],因此i要先算大的,j要先算小的
        //因此i从大到小遍历,j从小到大遍历
        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = 0; j < n; ++j)
            {
                //回文串长度为1
                if(i >= j) { dp[i][j] == '1'; continue; }
                //cout<<i<<"\t"<<j<<"\t"<<dp[i + 1][j - 1]<<endl;
                if(dp[i + 1][j - 1] == '1' && s[i] == s[j]) 
                { 
                    dp[i][j] == '1';
                    if(len < j - i +1) 
                    {
                        len = j - i + 1; 
                        beg = i,end = j;
                    }
                    continue; 
                }
                dp[i][j] = '0';
            }
        }
        //释放空间
        for(int i = 0;i < n; ++i) delete [] dp[i]; 
        delete[] dp;
        return s.substr(beg,end - beg + 1);
    }
};
//=======================Driver===========================
int main()
{
    Solution sol;
    string s("abcda");
    cout<<sol.longestPalindrome(s)<<endl;
    return 0;
}


/*
===========complexity==============
Time Complexity:O(n^2)
Space Complexity:O(n^2)
===========makefile=================
all:
    @g++  solve.cpp -o   solve
    @./solve
clean:
    rm -f solve
    reset
===========leetcode accepted========
93 / 93 test cases passed.
Status: Accepted
Runtime: 162 ms
Submitted: 0 minutes ago
===========submission date=========
2017.01.10
*/
