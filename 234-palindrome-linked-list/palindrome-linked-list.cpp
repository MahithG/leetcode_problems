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
    ListNode* prev = nullptr ;
    ListNode* front = nullptr ;
    while(head !=nullptr){
        front = head->next;
        head->next = prev ;
        prev = head ;
        head = front;
    }

   return prev ; }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        ListNode* nod = reverseList(slow->next);
        ListNode* first = head ;
        ListNode* second = nod ;
        while(second != nullptr){
            if(first->val != second->val) {
                reverseList(nod) ;
                  return false ;
            }
         first = first -> next;
         second = second -> next ;
        }
        reverseList(nod);
 return true ; }
};