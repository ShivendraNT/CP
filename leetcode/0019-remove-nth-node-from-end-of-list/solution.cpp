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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }
        int length=0;
        ListNode* curr=head;
        while(curr!=NULL){
            length++;
            curr=curr->next;
        }
        int pos=length-n-1;
        curr=head;
        
        while(pos>0){
            curr=curr->next;
            pos--;
        }
        if(pos==-1){
            head=head->next;
        }
        else{curr->next=curr->next->next;}
        return head;
    }
};
