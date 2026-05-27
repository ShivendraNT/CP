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
    ListNode* findmed(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL ){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* head=new ListNode(-1);
        ListNode* res=head;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                res->next=l1;
                res=l1;
                l1=l1->next;
            }
            else{
                res->next=l2;
                res=l2;
                l2=l2->next;
            }
        }
        if(l1!=NULL){
            res->next=l1;
        }
        if(l2!=NULL){
            res->next=l2;
        }
        return head->next;
    }
    ListNode* mergesort(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid=findmed(head);
        ListNode* right=mid->next;
        mid->next=NULL;
        ListNode* left=mergesort(head);
        right=mergesort(right);
        ListNode* newhead=merge(left,right);
        return newhead;
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};
