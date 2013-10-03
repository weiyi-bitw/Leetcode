#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL) return head;
        ListNode *p = head;
        if(p->next == NULL) return head;
        head = p->next;
        ListNode *q = p->next;
        ListNode *r = q->next;
        while(q != NULL){
            q->next = p;
            if(r == NULL){
                p->next = NULL;
                break;
            }else if(r->next == NULL){
                p->next = r;
                break;
            }
            p->next = r->next;
            p = r;
            q = p->next;
            r = q->next;
        }
        return head;        
    }
};

int main()
{
	int arr[7] = {2, 5, 3, 4, 6, 2, 2};
	ListNode *head = new ListNode(2);
	ListNode *p = head;
	for(int i = 1; i < 7; i++){
		p->next = new ListNode(arr[i]);
		p = p->next;
	}
	Solution sol;
	head = sol.swapPairs(head);
	p = head;
	while(p != NULL){
		cout << p->val << endl;
		p = p->next;
	}
	
	// clear the list
	while(head != NULL){
		p = head->next;
		delete head;
		head = p;
	}

	return 0;
}


