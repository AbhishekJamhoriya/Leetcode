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
    
    ListNode *reverse(ListNode *head){
        ListNode *prev=NULL;
        ListNode *ptr=head;
        while(ptr){
            ListNode *next=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=next;
        }
        return prev;
        
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *comp=reverse(slow->next);
        // cout<<comp->val;
        while(comp){
            if(head->val!=comp->val){
                return false;
            }
            head=head->next;
            // cout<<comp->val<<" ";
            comp=comp->next;
        }
        return true;
    }
};