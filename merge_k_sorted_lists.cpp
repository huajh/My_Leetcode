#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private: 
	ListNode* merge(ListNode* a, ListNode* b) // a, b are sorted
	{	
		ListNode* head = new ListNode(0);
		ListNode* tail = head;

		while (a != NULL || b != NULL)
		{			
			if (a == NULL)
			{
				tail->next = b;
				break;
			}
			else if (b == NULL)
			{
				tail->next = a;
				break;
			}
			else{
				if (a->val < b->val)
				{	
					tail->next = a;					
					tail = tail->next;
					a = a->next;				
				}
				else{
					tail->next = b;
					tail = tail->next;
					b = b->next;					
				}
			}			
		}
		return head->next;

	}
	struct compare
	{
		bool operator() (const ListNode* l1, const ListNode* l2)
		{
			return l1->val > l2->val;
		}
	};
public:

	// using priority queue
	ListNode* mergeKLists(vector<ListNode*>& lists)  // 
	{
		priority_queue<ListNode*, vector<ListNode*>, compare> que;
		for (auto i : lists)
		{
			if (i) que.push(i);			
		}		
		ListNode* head = new ListNode(0);
		ListNode* tail = head;
		while (!que.empty())
		{
			tail->next = que.top();
			que.pop();
			tail = tail->next;
			if (tail->next)
				que.push(tail->next);
		}
		return head->next;
	}


	// merge sort
	ListNode* mergeKLists2(vector<ListNode*>& lists)  // 
	{
		if (lists.empty())
		{
			return NULL;
		}
		int k = lists.size();		
		if (k == 1)
			return lists[0];
		if (k == 2)
		{
			return merge(lists[0],lists[1]);			
		}
		int mid = k / 2;		
		vector<ListNode*> left(lists.begin(),lists.begin() + mid );
		vector<ListNode*> right(lists.begin() + mid , lists.end());
		ListNode* a = mergeKLists(left);	
		ListNode* b = mergeKLists(right);
		return merge(a, b);		
	}

};

void main()
{
	Solution sol;
	ListNode * head  =	NULL;
	
	ListNode * head2;
	ListNode a2(-1), b2(5), c2(11);
	head2 = &a2;
	a2.next = &b2;
	b2.next = &c2;

	ListNode * head0 = NULL;
	ListNode * head3;
	ListNode a3(6), b3(9);
	head3 = &a3;
	a3.next = &b3;

	vector<ListNode*> lists;
	lists.push_back(head);
	lists.push_back(head2);
	lists.push_back(head0);
	lists.push_back(head3);

	ListNode* ans = sol.mergeKLists(lists);  // 
}

