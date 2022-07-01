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
    
    int lengthof(ListNode *head){
        int n=0;
        while(head){
            head=head->next;
            n++;
        }
        return n;
    }
    
    ListNode *solve(ListNode *root,int k){
        ListNode *slow=root;
        ListNode *fast=root;
        while(k--){
            fast=fast->next;
            
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode *temp=slow->next;
        slow->next=NULL;
        fast->next=root;
        return temp;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int n=lengthof(head);
        if(n==0 || n==1 || k==0 || k%n==0){
            return head;
        }
        k=k%n;
        
        ListNode *ans=solve(head,k);
        return ans;
    }
};