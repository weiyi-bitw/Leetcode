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

// OJ: 136 ms

class Solution {
public:
    ListNode *reverse(ListNode *head, ListNode* end){
        ListNode *p = head, *q = p->next, *r = q->next;
        head->next = end;
        while(q != end){
            q->next = p;
            p = q;
            q = r;
            if(r != NULL) r = r->next;
        }
        head = p;
        return head;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k < 2 || head == NULL) return head;
        ListNode *p = head, *q = NULL;
        ListNode *ed = p;
        bool first = true;
        while(p != NULL){
            for(int i = 1; i < k; i++){
                if(q) q = q->next;
                ed = ed->next;
                if(ed == NULL) return head;
            }
            ed = ed->next;
            p = reverse(p, ed);
            if(q) q->next = p;
            q = p;
            if(first){
                head = p;
                first = false;
            }
            p = ed;
        }
        return head;
    }
};

int main()
{
	int arr[10] = {8, 9, 8, 8, 5, 7, 7, 0, 3, 5};
	ListNode *head = new ListNode(arr[0]);
	ListNode *p = head;
	for(int i = 1; i < 10; i++){
		p->next = new ListNode(arr[i]);
		p = p->next;
	}
	Solution sol;
	head = sol.reverseKGroup(head, 3);

	p = head;
	while(p){
		cout << p->val << endl;
		p = p->next;
	}
	
	// clear the list
	while(head){
		p = head->next;
		delete head;
		head = p;
	}

	return 0;
}


