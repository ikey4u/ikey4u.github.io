#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(),n = nums2.size();
        if((m + n) % 2 == 0)
            return (FindKth(nums1,nums2,(m + n) / 2) + FindKth(nums1,nums2,(m + n) / 2 + 1))  / 2.0;
        else
            return FindKth(nums1,nums2,(m + n + 1) / 2);
    }
    //找到第k个最大的数,K应小于等于m+n,这里未做验证
    int FindKth(vector<int> &M,vector<int>& N,int K)
    {
        int m = M.size(),n = N.size();
        //设置M为较短的数组
        if(m > n) return FindKth(N,M,K);
        //边界条件:注意下面两行不能互换,因为可能在K == 1时,较短的数组M可能为空
        //比如M=[1,2] N=[3,4]
        if(m == 0) return  N[K - 1];
        if(K == 1) return min(M[0],N[0]);
        //M和N的指针分别设置为pm,pn,使得pm+pn=K
        int pm = min(K / 2,m);
        int pn = K - pm;
        //如果M上的一段必定位于前K个数中
        if(M[pm - 1] < N[pn - 1])
        {
            vector<int> vec(M.begin() + pm,M.end());
            return FindKth(vec,N,K - pm);
        }
        //否则在N上的一段必然属于前K个数中
        else
        {
            vector<int> vec(N.begin() + pn,N.end());
            return FindKth(M,vec,K - pn);
        }
    }
    //调试函数
    void PrintVector(vector<int> vec)
    {
        for(vector<int>::iterator pos = vec.begin(); pos != vec.end(); ++pos)
            if(pos + 1 == vec.end()) cout<<*pos<<endl;
            else cout<<*pos<<"  ";
    }
};
//=======================Driver===========================
int main()
{
    int M[] = {1,2};
    int N[] = {3,4};
    vector<int> nums1(M,M + sizeof(M) / sizeof(int));
    vector<int> nums2(N,N + sizeof(N) / sizeof(int));
    Solution s;
    cout<<s.findMedianSortedArrays(nums1,nums2)<<endl;
    //cout<<s.SearchPos(nums1,2);
    return 0;
}


/*
===========complexity==============
Time Complexity:O(log(m+n))
Space Complexity:O(1)
===========makefile=================
all:
    @g++  solve.cpp -o   solve
    @./solve
clean:
    rm -f solve
    reset
===========leetcode accepted========
2080 / 2080 test cases passed.
Status: Accepted
Runtime: 32 ms
Submitted: 0 minutes ago
===========submission date=========
2017-01-09 Mon 11:03 PM
*/
