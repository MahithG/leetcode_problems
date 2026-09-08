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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head ;
        ListNode* front ;
        if(head != nullptr) front = head->next ;
        while(temp != nullptr && front != nullptr){
            if(temp->val == front->val){
                temp->next = front->next;
                front->next  = nullptr ;
                delete front ;
                front = temp->next;
            }
            else{
                temp = temp->next ;
                front = front->next ;
            }
        }
   return head ; }
};