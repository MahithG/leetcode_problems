/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head ;
        map<ListNode*,int> mp;
        while(temp != nullptr){
             mp[temp]++;
             if(mp[temp] > 2) return temp ;
            temp=temp->next ;
           
        }
    return 0;}
};