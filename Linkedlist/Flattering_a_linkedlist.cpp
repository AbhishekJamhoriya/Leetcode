Node *merge(Node *one,Node *two){
    Node *prev=NULL;
   Node *ptr=one;
    while(one && two){
        if(one->data<=two->data){
            prev=one;
            one=one->bottom;
        }
        else{
            prev->bottom=two;
            Node *temp=two->bottom;
            two->bottom=one;
            prev=two;
            two=temp;
        }
    }
    if(two){
        prev->bottom=two;
    }
    return ptr;
}
    
Node *flatten(Node *root)
{
   Node *ptr=root;
  
   Node *temp=ptr->next;
    ptr->next=NULL;
   while(temp){
       Node *val=temp->next;
       temp->next=NULL;
       if(ptr->data<=temp->data){
            Node *result=merge(ptr,temp);
            ptr=result;
       }
       else{
         Node *result=merge(temp,ptr);
            ptr=result;  
       }
      
       
       temp=val;
       
   }
   return ptr;
   
}

