//create circular linklist

#include<stdio.h>
#include<stdlib.h>

//declaration
struct Node{
    int data;
    struct Node* next;
};

//insert at start
 struct Node* addstart(struct Node* head ,int data){
    struct Node* ptr=malloc(sizeof(struct Node));   //to place element
    ptr->data=data;

    struct Node* point=head->next;      //traverse

    while(point->next != head){
        point=point->next;
    }     
    //point pointing to last node of list

    point->next=ptr ;   
    ptr->next=head;

    head=ptr;

    return head;
}

//delete at start
struct Node* delstart(struct Node* head){
    if(head==NULL){
        printf("List is Empty");    //empty case
    }
    else if(head->next==head){      //single node case
        head=NULL;
        free(head);
    }
                                    //multi node case
    struct Node* ptr=head;      
    while(ptr->next!=head){  
        ptr=ptr->next;
    }
    ptr->next=head->next;   //ptr is now at 2nd positioin
    free(head); 
    head=ptr->next;        //head=NULL is now head=2nd
}
//insert at end
 struct Node* addend(struct Node* head ,int data){
    struct Node* ptr=malloc(sizeof(struct Node));   //to place element
    ptr->data=data;
    ptr->next=NULL;        //to space for next element

    struct Node* point=head->next;      //traverse

    while(point->next != head){
        point=point->next;
    }     
    //point pointing to last node of list

    point->next=ptr ;   
    ptr->next=head;

    return head;
}

//delete at end
struct Node* delend(struct Node* head){
    if(head==NULL){
        printf("List is Empty");
    }
    else if(head->next==head){
        head=NULL;
        free(head);
    }

    struct Node* ptr=head;
    while(ptr->next->next!=head){    //next of next is one step before head
        ptr=ptr->next;
    }
    struct Node* tail=ptr->next;    //tail now have ptr->next value which is end
    ptr->next=head;                 //head pointing to end or we can say one step back
    free(tail);                     // now tail is free so we can remove it
    return head;
}

// //insert at specific position
// struct Node* addpost(struct Node* head,int n,int data){
//     struct Node* ptr=malloc(sizeof(struct Node));
//     ptr->data=data;

//     struct Node* point=head->next;

//     while(point!=n){
//         point=point->next;
//     }
//     point->next=ptr;
//     ptr->next=head;
//     head=ptr;

//     return head;
// }

 int main(void){

    //creating structure nodes 
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node* two=(struct Node*)malloc(sizeof(struct Node));;
    struct Node* three=(struct Node*)malloc(sizeof(struct Node));;

    //data and link
    head->data=10;          //first
    head->next=two;

    two->data=20;          //second
    two->next=three;
    
    three->data=30;        //three
    three->next=head;

    //insert at start
    head=addstart(head,40);

    //delete at start
    head=delstart(head);

    //insert at end
    head=addend(head,50);

    //delete at end
    head=delend(head);

    // //insert at specific position
    // head=addpost(head,2,100);

    //printing
    struct Node* ptr=head;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
 }