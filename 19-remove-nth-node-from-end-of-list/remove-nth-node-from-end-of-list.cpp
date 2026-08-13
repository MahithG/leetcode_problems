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
        if(head == nullptr || head->next == nullptr) return nullptr ;
        ListNode* temp = head ;
        int count = 0;
        int k = 0;
        while(temp !=nullptr){
       count ++ ;
       temp = temp->next ;
        }
    k = count - n ;
    temp = head ;
    ListNode* pre = temp ;
    if(k == 0){
        head = head->next ;
        temp->next = nullptr;
        delete temp;
        return head ;
    }
    while(k>0){
        pre = temp ;
        temp = temp->next ;
        k-- ;
    }
    pre->next = pre->next->next;
    temp->next = nullptr;
    delete temp ;
   return head ; }
};