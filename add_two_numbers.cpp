
#include <iostream>
#include<string>
#include<vector>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

void addnode(ListNode** pnode, int val)
{
        ListNode * nextnode = new ListNode(val);
        (*pnode)->next = nextnode;
        *pnode = (*pnode)->next;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        
        
        int a=0,b=0;
        ListNode* l3 = new ListNode(0);
        ListNode* phead = l3;

        while(l1!=NULL && l2!= NULL)
        {
            a = (l1->val + l2->val + b)%10;
            b = (l1->val + l2->val + b)/10;

            addnode(&l3, a);

            //ListNode * nextnode = new ListNode(a);
            //l3->next = nextnode;
            //l3 = l3->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l2 != NULL)
        {
            a = ( l2->val + b)%10;
            b = ( l2->val + b)/10;

            addnode(&l3, a);
            l2 = l2->next;
        }
        while(l1 != NULL)
        {
            a = ( l1->val + b)%10;
            b = ( l1->val + b)/10;
            
            addnode(&l3, a);
            l1 = l1->next;
        }

        if (b!=0)
        {
            addnode(&l3, b);
        }

        ListNode * head = phead;
        phead = phead->next;
        delete head;

        return phead;
       
    }
};


int main()
{
    // 243
    ListNode*  l1_head = new ListNode(5), *l1_second = new ListNode(4), *l1_third = new ListNode(3);
    l1_head->next = l1_second;
    l1_second->next = l1_third;

    //564
    ListNode* l2_head = new ListNode(5), *l2_second = new ListNode(6), *l2_third = new ListNode(4);
    l2_head->next = l2_second;
    l2_second->next = l2_third;

    Solution sol;

    ListNode* res = sol.addTwoNumbers(l1_head, l2_head);

    //708

    cout<<res->val<<"->"<<res->next->val<<"->"<<res->next->next->val<<endl;
    
    return 0;
}
