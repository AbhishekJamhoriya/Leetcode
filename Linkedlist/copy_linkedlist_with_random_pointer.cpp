/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        Node *ptr=head;
        while(ptr){
            Node *next=ptr->next;
            ptr->next=new Node(ptr->val);
            ptr->next->next=next;
            ptr=next;
        }
        ptr=head;
        while(ptr){
            Node *next=ptr->next;
            if(ptr->random==NULL){
                next->random=NULL;
            }
            else{
                next->random=ptr->random->next;
            }
            ptr=next->next;
            
        }
        ptr=head;
        Node *ans=ptr->next;
        Node *prev=NULL;
        while(ptr){
            Node *next=ptr->next;
            if(next->next){
                ptr->next=next->next;
                if(prev==NULL){
                    prev=next;
                }
                else{
                    prev->next=next;
                }
                prev=next;
            }
            else{
                ptr->next=NULL;
                if(prev==NULL){
                    prev=next;
                }
                else{
                    prev->next=next;
                }
                prev=next;
            }
            ptr=next->next;
        }
        // prev->next=NULL;
        return ans;
    }
};