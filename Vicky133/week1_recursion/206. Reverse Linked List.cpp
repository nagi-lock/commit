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
    ListNode* reverseList(ListNode* head) {
        //recursion
        if(head==NULL || head->next==NULL)return head;
        ListNode* newHead = reverseList(head->next); 
        ListNode* forword = head->next;
        head->next = NULL;
        forword->next = head;
        return newHead;
        // TC:O(n) 
        // SC:O(n) stack space

        // ListNode *prev=NULL,*temp=head;
        // while(temp!=NULL){
        //     ListNode* front = temp->next;
        //     temp->next=prev;
        //     prev=temp;
        //     temp=front;
        // }
        // return prev;
        // TC: O(n)
        // SC: O(1)
    }
};