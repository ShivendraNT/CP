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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newhead=reverse(head->next);
        ListNode* prev=head->next;
        prev->next=head;
        head->next=NULL;
        return newhead;
    }
    int pairSum(ListNode* head) {
        int maxsum=-1;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* init=head;
        ListNode* half=reverse(slow);
        while(half!=NULL){
            maxsum=max(maxsum,init->val+half->val);
            init=init->next;
            half=half->next;
        }
        return maxsum;
    }
};
