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
    ListNode* middleLL(ListNode * head){
        ListNode * slow = head;
        ListNode * fast= head;
        ListNode * s1= NULL;

        while(fast && fast->next){
            s1 = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return s1; //return middle 1 in even to find correct point to break;
    }


    ListNode* mergeLL(ListNode * left , ListNode * right){
        ListNode* t1 = left;
        ListNode* t2 = right;
        ListNode* dummy = new ListNode(-1);
        ListNode * temp = dummy;

        while(t1 &&  t2){
            if(t1->val< t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if(t1) temp->next = t1;
        else temp->next = t2;

        return dummy->next;


    }

    ListNode* sortList(ListNode* head) {
        ListNode* middle = middleLL(head);
        if(!head || !head->next) return head;
        ListNode * left = head;
        ListNode * right = middle->next;
        middle->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return mergeLL(left,right);

    }
};