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
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            return head;
        }
        //leap of faith till last Node and hits base case.
        ListNode* newNode = reverseList(head->next);

        //now recursive call at second last node.
        ListNode* temp = head->next;
        temp->next = head;
        head->next = nullptr;

        return newNode;
    }
};