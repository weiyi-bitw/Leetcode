/*
 * =====================================================================================
 *
 *       Filename:  addTwoNumbers.cpp
 *
 *    Description:  Judge small: 8 msec; Judge large: 184 msec
 *
 *        Version:  1.0
 *        Created:  09/15/2013 12:05:43 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(NULL){}
};

ListNode *initiateLinkedList(int A[], int n)
{
	ListNode *head = new ListNode(A[0]);
	ListNode *lp = head;
	for(int i = 1; i < n; i++){
		lp->next = new ListNode(A[i]);
		lp = lp->next;
	}
	return head;
}

class Solution{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		bool carry = false;
		ListNode *head = NULL;
		ListNode *lp;
		while(l1 != NULL || l2 != NULL){
			int k = carry;
			if(l1 != NULL){ 
				k += l1->val;
				l1 = l1->next;
			}
			if(l2 != NULL){ 
				k += l2->val;
				l2 = l2->next;
			}

			if(k > 9){
				k -= 10;
				carry = true;
			}else{
				carry = false;
			}
			if(head == NULL){ 
				head = new ListNode(k);
				lp = head;
			}else{ 
				lp->next = new ListNode(k);
				lp = lp->next;
			}
		}
		if(carry)
			lp->next = new ListNode(1);
		
		return head;
	}

};

int main()
{
	int A[2] = {1, 8};
	int B[1] = {0};
	Solution sol;
	ListNode *l1 = initiateLinkedList(A, 2);
	ListNode *l2 = initiateLinkedList(B, 1);
	ListNode *lout = sol.addTwoNumbers(l1, l2); 

	ListNode *lp = lout;
	while(lp != NULL){
		cout << lp->val << endl;
		lp = lp->next;
	}
	return 0;
}
