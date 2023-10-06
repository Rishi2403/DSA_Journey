    Node* prevptr=NULL;
    Node* currptr=head;

    int counter=0;
    while(currptr!=NULL && counter<k){ //reversing k nodes
        Node* nextptr=currptr->next;
        currptr->next=prevptr;
        currptr=nextptr;
        counter++;
    }
    //currptr will return k+1 node
    if(currptr!=NULL){
        Node* new_head=reversekll(currptr,k);
        head->next=new_head;
    }

    return prevptr;// will return the new head of connected linked list