#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        //如果行为1,则不需要转换
        if(numRows == 1) return s;
        //返回字符串初始为空
        string ss("");
        //行数,字符串长度
        int rows = numRows,len = s.length();
        //zz的长度 zz的数目
        int ziglen = rows + (rows - 2);
        int zigcnt = ceil(len * 1.0 / ziglen);
        for(int i = 0;i < rows;++i)
        {
            int p = i;
            //第一行和最后一行,只需缀一次
            if(i == 0 || i == rows - 1)
                for(int j = 0;j < zigcnt && p < len; ++j)
                {
                    ss += s[p];
                    p += ziglen;
                }
            //其他行则需缀两次
            else
                for(int j = 0;j < zigcnt;++j)
                {
                    if(p < len) ss += s[p];
                    //边界索引和ziglen * (2 * j + 1)
                    if(ziglen * (2 * j + 1) - p < len) ss += s[ziglen * (2 * j + 1) - p];
                    p += ziglen;
                }
        }
        return ss;
    }
};
//=======================Driver===========================
int main()
{
    Solution sol;
    //cout<<sol.convert("PAYPALISHIRING", 3)<<endl;
    //cout<<sol.convert("", 1)<<endl;
    cout<<sol.convert("A", 2)<<endl;
    return 0;
}


/*
===========complexity==============
Time Complexity:O(n))
Space Complexity:O(1)
===========makefile=================
all:
    @g++  solve.cpp -o   solve
    @./solve
clean:
    rm -f solve
    reset
===========leetcode accepted========
1158 / 1158 test cases passed.
Status: Accepted
Runtime: 16 ms
Submitted: 0 minutes ago
===========submission date=========
2017-01-14 Sat 08:08 PM
*/
