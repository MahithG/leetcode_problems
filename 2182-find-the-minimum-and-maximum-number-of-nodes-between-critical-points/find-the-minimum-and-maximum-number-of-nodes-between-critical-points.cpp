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
#include <iostream>
#include <vector>
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>l;
        int ans[] ={-1,-1} ;
        ListNode* prev = head ;
        ListNode* temp = head->next ;
        ListNode *front = head->next->next ;
        int pos = 1;
        while(front != nullptr){
            if(temp->val>prev->val && temp->val>front->val){
                l.push_back(pos);
            }
            else if(temp->val<prev->val && temp->val<front->val){
                l.push_back(pos);
            }
            front = front->next ;
            temp = temp->next ;
            prev = prev->next;
            pos++ ;
        } 
        if(l.size() >=2 ){
        std::sort(l.begin(), l.end());
        int min_diff = INT_MAX;
        for (int i = 1; i < l.size(); ++i) {
        min_diff = std::min(min_diff, l[i] - l[i - 1]);
        }
        int max_diff = l[l.size()-1]-l[0];
        ans[0] = min_diff ;
        ans[1] = max_diff ;}

   return {ans[0],ans[1]} ; }
};