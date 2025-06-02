/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int LengthLL(ListNode *head){
        int s = 0;
        while(head){
            head = head->next;
            s++;
        }
        return s;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next && n == 1) return NULL;

        int len = LengthLL(head);
        int k  = len - n;
        ListNode * temp = head;
         if(k ==0){
           
            head = head->next;
             temp->next = NULL;
            return head;
        }
        while(k>1 ){
           
            temp = temp->next;
           k--; 
        }
       
        ListNode* node = temp->next;
        temp->next = node->next;
         node->next = NULL;

        return head;
    }
};