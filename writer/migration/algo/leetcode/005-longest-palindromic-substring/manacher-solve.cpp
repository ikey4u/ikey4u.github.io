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
        if(n == 0) return s;
        //预处理,将字符串以'|'竖线分割开来
        char split = '|';
        string str(2 * n + 1,split);
        for(int i = 0;i < 2 * n + 1; ++i)
            if(i % 2 == 1) str[i] = s[(i - 1) / 2];
        //LPS数组
        int *d = new int[2 * n + 1]; memset(d,0,(2 * n + 1) * sizeof(int));
        d[0] = 0;
        //初始中心点,右边界
        int m = 0,mr = 0;
        //最大偏移,最大长度对应的元素索引
        int dmax = 0,dindex = 0;
        for(int i = 1;i < 2 * n + 1; ++i)
        {
            //i'=2m-i
            //若d[i']<i'-ml=mr-i ==> d[i]=d[i']
            //若d[i']>i'-ml=mr-i ==> d[i]>=mr-i,可取mr-i
            if(i < mr) d[i] = min(d[2 * m - i],mr - i);
            //当i>=mr时,取0
            else d[i] = 0;
            //进一步调整d[i]为最终值,这里比较经典的一行代码
            while(str[i - d[i] - 1] == str[i + d[i] + 1] )
            {
                ++d[i];
                //边界校验
                if(i - d[i] - 1 < 0 || i + d[i] + 1 > 2 * n) break;
            }
            if(d[i] > dmax) { dmax = d[i];dindex = i; }
            //更新中心点m和右边界mr
            if(i + d[i] > mr) {m = i;mr = i + d[i];}
        }
        //返回值的边界值(dindex-dmax),(dindex+dmax)
        delete[] d;
        return s.substr((dindex - dmax) / 2,(dindex + dmax - (dindex - dmax) + 1) / 2);
    }
};
//=======================Driver===========================
int main()
{
    Solution sol;
    string s("cdbabcbabdbab");
    /*
    |a|b|c|d <=索引转换=> abcd
        0,1               0  
        2,3               1
        4,5               2
    所以(左/2)==>右
    */
    cout<<sol.longestPalindrome(s)<<endl;
    return 0;
}


/*
===========complexity==============
Time Complexity:O(n)
Space Complexity:O(n)
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
Runtime: 6 ms
Submitted: 0 minutes ago
===========submission date=========
2017-01-12 Thu 11:40 PM
*/
