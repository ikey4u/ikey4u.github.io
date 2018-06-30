#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.length() == 0) return 0;
        //字符串s的最长不重复子串长度
        int maxlen = 1;
        //以j结尾的最长不重复子串长度
        int jmaxlen = 1;
        for(int j = 1;j < s.length();++j)
        {
            int repeat = 0;
            for(int i = j - 1;i >= j - jmaxlen;--i)
            {
                //如果以j-1结尾的最长不重复子字符串含有s[j],且s[i]==s[j]
                //则以j结尾的最长不重复子字符串长度为j-(i+1)+1
                if(s[i] == s[j]) 
                {
                    jmaxlen = j - (i + 1) +1; 
                    repeat = 1;
                    break;
                }
            }
            //如果以j-1结尾的最长不重复子字符串不含有s[j],则s[i]==s[j]
            //则以j结尾的最长不重复子字符串长度为jmaxlen+1
            if(!repeat) jmaxlen += 1;
            maxlen = maxlen > jmaxlen ? maxlen : jmaxlen;
        }
        return maxlen;
    }
};
//=======================Driver===========================
int main()
{
    Solution sol;
    string s("abcabcbb");
    cout<<sol.lengthOfLongestSubstring(s)<<endl;
    return 0;
}


/*
===========complexity==============
记字符串长度为n
Time Complexity:O(n^2))
Space Complexity:O(1)
===========makefile=================
all:
	@g++  solve.cpp -o   solve
	@./solve
clean:
	rm -f solve
	reset
===========leetcode accepted========
第一种:
983 / 983 test cases passed.
Status: Accepted
Runtime: 32 ms
Submitted: 0 minutes ago
第二种
===========submission date=========
2017-01-07 Sat 03:42 PM
*/
