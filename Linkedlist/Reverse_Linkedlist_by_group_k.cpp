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
    
    ListNode *solve(ListNode *head,int n,int k){
        if(head==NULL){
            return NULL;
        }
        if(n<k){
            return head;
        }
        ListNode *ptr=head,*temp=head,*prev=NULL,*next=NULL;
        int l=k;
        while(ptr && l--){
            next=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=next;
            
        }
     
            temp->next=solve(ptr,n-k,k);
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        if(k==1){
            return head;
        }
        ListNode *ptr=head;
        while(ptr){
            ptr=ptr->next;
            n++;
        }
        ListNode *ans=solve(head,n,k);
        return ans;
    }
};