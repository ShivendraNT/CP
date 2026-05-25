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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        k=k%len;
        int step=len-k;
        temp=head;
        for(int i=0;i<step-1;i++){
            temp=temp->next;
        }
        ListNode* orghead=head;
        ListNode* nxt=temp->next;
        
        temp->next=NULL;
        if(nxt==NULL){
            return head;
        }
        head=nxt;
        while(nxt->next!=NULL){
            nxt=nxt->next;
        }
        nxt->next=orghead;
        return head;
    }
};
