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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *first=list1;
        ListNode *second=list2;
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode *head=NULL;
        ListNode *prev=NULL;
        while(first && second){
            if(first->val<=second->val){
                if(!head){
                    head=first;
                }
                prev=first;
                first=first->next;
                
            }
            else{
                 if(!head){
                    head=second;
                }
                 ListNode *next=second->next;
                ListNode*temp=second;
               if(!prev){
                  
                   second->next=first;
                   
               }
                else{
                    prev->next=second;
                    second->next=first;
                    
                    
                }
                prev=second;
                second=next;
            }
        }
        if(second){
            if(prev){
             prev->next=second;   
            }
            else{
                head=second;
            }
            
        }
        return head;
    }
};