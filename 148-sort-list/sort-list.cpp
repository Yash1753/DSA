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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        vector<int>s;
        ListNode * temp = head;
        while(temp){
            s.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        
        sort(s.begin(),s.end());

        for(auto it: s){
            temp->val = it;
            temp = temp->next;
        }

        return head;

    }
};