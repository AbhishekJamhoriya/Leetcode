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
    int solve(ListNode *head){
        if(!head){
            return 0;
        }
        int a=1;
        while(head){
            head=head->next;
            a++;
        }
        return a;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=solve(headA);
        int n=solve(headB);
        if(n>m){
            while(n!=m){
                headB=headB->next;
                n--;
            }
        }
        else{
           while(n!=m){
                headA=headA->next;
                m--;
            } 
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};