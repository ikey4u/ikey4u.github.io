#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution 
{
public:
    //int ov = -1;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        cout<<endl<<endl;
        cout<<"-->"<<endl;
        PrintVector(nums1); PrintVector(nums2);
        cout<<"<--"<<endl;
        int m = nums1.size(); int im = (m - 1) /2;
        int n = nums2.size(); int in = (n - 1) /2;
        //if(ov == -1) ov = (m + n) % 2; //标记所有元素的个数是奇数还是偶数

        //当至少有一个数组的个数小于3时,停止递归
        if(m < 3 && n < 3)
        {
            if(m == 1)
                if( (m + n) % 2 == 1)
                {
                    if(nums1[0] > nums2[in]) return nums1[0] * 1.0;
                    else return nums2[in] * 1.0;
                }
                else if((m + n) % 2 == 0)
                {
                    int pos = SearchPos(nums2,nums1[0]);
                    //由于总共有偶数个,中位数必然位于中间两个数之间
                    //il和ir分别指向这两个数,有ir-il==1
                    int il = (m + n - 1) / 2,ir = (m + n) / 2;
                    if(ir == pos) return (nums2[il] + nums1[0]) / 2.0;
                    if(ir < pos) return (nums2[il] + nums2[ir]) / 2.0;
                    if(il == pos) return (nums1[0] + nums2[ir - 1]) / 2.0; 
                    if(il > pos) return (nums2[il - 1] + nums2[ir - 1]) / 2.0;
                }
            if(m == 2)
        }
        else if(m >= 3 && n >= 3)
        {
            //当KM==KN时
            if(nums1[im] == nums2[in])
            {
                cout<<"KM=KN"<<endl;
                if( (m + n) % 2 == 1 ) return nums1[im] * 1.0;
                else if( (m+n) % 2 == 0 ) 
                {
                    //两个都是偶数
                    if(m % 2 == 0) return (nums2[in] + min(nums1[im + 1],nums2[in + 1]))/2.0;
                    else if(m % 2 == 1) return nums1[im] * 1.0;
                }
            }
            //当KM<KN时
            if(nums1[im] < nums2[in])
            {
                
                cout<<"KM<KN"<<endl;
                vector<int> M(nums1.begin() + (m + 1) / 2 - 1,nums1.end());
                vector<int> N(nums2.begin(),nums2.begin() + (n + 1) / 2);
                return findMedianSortedArrays(M,N);
            }
            //当KM>KN时
            if(nums1[im] > nums2[in])
            {
                cout<<"KM>KN"<<endl;
                vector<int> M(nums1.begin() + (m + 1) / 2 - 1,nums1.end());
                vector<int> N(nums1.begin(),nums1.begin() + (n + 1) / 2);
                return findMedianSortedArrays(M,N);
            }
        }
        //m和n中一个大于3,一个小于3
        else
        {
            
        }
    }
    void PrintVector(vector<int> vec)
    {
        for(vector<int>::iterator pos = vec.begin(); pos != vec.end(); ++pos)
            if(pos + 1 == vec.end()) cout<<*pos<<endl;
            else cout<<*pos<<"  ";
    }
    int SearchPos(vector<int> vec,int val)
    {
        int low = 0,high = vec.size();
        //最后一次循环是low==high
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(vec[mid] == val) return mid;
            if(vec[mid] > val) high = mid - 1;
            if(vec[mid] < val) low = mid + 1;
        }
        return low;
    }
};
//=======================Driver===========================
int main()
{
    int M[] = {1,3,4,5};
    int N[] = {3,4};
    vector<int> nums1(M,M + sizeof(M) / sizeof(int));
    vector<int> nums2(N,N + sizeof(N) / sizeof(int));
    Solution s;
    //cout<<s.findMedianSortedArrays(nums1,nums2)<<endl;
    cout<<s.SearchPos(nums1,2);
    return 0;
}


/*
===========complexity==============
===========makefile=================
===========leetcode accepted========
===========submission date=========
*/
