#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;
		ListNode* first = head, *second = first->next, *before = first, *after = second->next;
		first->next = NULL;
		head = second;
		after = second->next;
		second->next = first;
		first = after;
		while (first !=NULL)
		{	
			if (first->next == NULL)
			{
				before->next = first;
				break;
			}			
			second = first->next;	
			first->next = NULL;
			after = second->next;
			before->next = second;
			second->next = first;	
			before = first;
			first = after;
		}
		return head;
	}
};
int  main()
{
	Solution sol;
	ListNode node1(1), node2(2), node3(3), node4(4),node5(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	ListNode* head = & node1;
	sol.swapPairs(head);

    return 0;

}
