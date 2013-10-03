#include <iostream>

using namespace std;

// OJ : 88ms

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = lists.size();
        ListNode *head = NULL, *ln;
        
        while(true){
            ListNode* minLn = NULL;
            int minIdx = -1;
            for(int i = 0; i < k; i++){
                if(lists[i] != NULL){
                    if(minLn == NULL){ 
                        minLn = lists[i];
                        minIdx = i;
                    }else if(lists[i]->val < minLn->val){
                        minLn = lists[i];
                        minIdx = i;
                    }
                }
            }
            if(minLn == NULL) break;
            else{
                lists[minIdx] = lists[minIdx]->next;
            }
            if(head == NULL){
                head = minLn;
                ln = head;
            }else{
                ln->next = minLn;
                ln = ln->next;
            }
        }
        return head;
    }
};
