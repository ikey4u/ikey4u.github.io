#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* LA, ListNode* LB) 
    {
        int carry = 0; //前面传来的进位
        ListNode *LC = new ListNode(0);
        ListNode *p = LC;
        while(LA && LB)
        {
            int sum = LA->val + LB->val + carry;
            //取低位
            p->val = sum % 10;
            //取进位
            carry = sum / 10;
            //如果下一次循环两个链表都没有走到尽头,则分配下一个节点
            if(LA->next && LB->next)
            {
                ListNode *node = new ListNode(0);
                p->next = node; 
                p = node;
            }
            LA = LA->next;
            LB = LB->next;
        }
        //下面的两个while最多只有一个会执行
        while(LA)
        {
            ListNode *node = new ListNode(0);
            node->val = (LA->val + carry) % 10;
            carry = (LA->val + carry) / 10;
            p->next = node; p = node;
            LA = LA->next;
        }
        while(LB)
        {
            ListNode *node = new ListNode(0);
            node->val = (LB->val + carry) % 10;
            carry = (LB->val + carry) / 10;
            p->next = node; p = node;
            LB = LB->next;
        }
        //如果所有元素都处理完,仍有进位,那么该位为最高位
        if(carry)
        {
            ListNode *node = new ListNode(0);
            node->val = carry;
            p->next = node;
        }
        return LC;
    }
    //从数组创建链表
    ListNode *CreateList(int* arr,int n)
    {
        ListNode *L = new ListNode(0);
        ListNode *p = L;
        for(int i = 0;i < n;++i)
        {
            p->val = arr[i];
            if(i+1 == n) continue; 
            ListNode *node = new ListNode(0);
            p->next = node;
            p = node;
        }
        return L;
    }
    //打印链表
    void PrintList(ListNode* L)
    {
        while(L)
        {
            cout<<L->val;
            if(L->next) cout<<"->";
            L = L->next;
        }
        cout<<endl;
    }
};
//=======================Driver===========================
int main()
{
    int la[] = {5};
    int lb[] = {5};
    Solution s;
    ListNode *LA = s.CreateList(la,sizeof(la)/sizeof(int)); s.PrintList(LA);
    ListNode *LB = s.CreateList(lb,sizeof(lb)/sizeof(int)); s.PrintList(LB);
    ListNode *LC=s.addTwoNumbers(LA,LB); s.PrintList(LC);
    return 0;
}


/*
===========complexity==============
记链表LA,LB的长度分别是m,n:
Time Complexity:O(max(m,,n))
Space Complexity:O(max(m,n))
===========makefile=================
all:
	@g++  solve.cpp -o   solve
	@./solve
clean:
	rm -f solve
	reset
===========leetcode accepted========
1562 / 1562 test cases passed.
Status: Accepted
Runtime: 33 ms
Submitted: 0 minutes ago
===========submission date=========
2017-01-07 Sat 01:14 PM
*/
