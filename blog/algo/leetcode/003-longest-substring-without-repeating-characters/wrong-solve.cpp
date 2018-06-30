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
            int pos = find(s,j-jmaxlen,j-1,s[j]);
            if(pos == -1) jmaxlen += 1;
            else jmaxlen = j - (pos + 1) +1; 
            maxlen = maxlen > jmaxlen ? maxlen : jmaxlen;
        }
        return maxlen;
    }
    int find(string s,int i,int j,char c)
    {
        //递归终止条件
        if(i > j) return  - 1;   
        int mid = (i + j) / 2;
        //检测是否位于中间
        if(s[mid] == c) return mid;
        //检测是否位于右侧
        int right = find(s,mid + 1,j,c);
        if(right != -1) return right;
        //检测是否位于左侧
        int left = find(s,i,mid - 1,c);
        if(left != -1) return left;
        //不在右侧,不在左侧也不在中间
        return -1;
    }
};
//=======================Driver===========================
int main()
{
    Solution sol;
    string s("bbbbb");
    cout<<s.length()<<endl;
    cout<<sol.lengthOfLongestSubstring(s)<<endl;
    return 0;
}
