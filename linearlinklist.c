//create linklist

#include<stdio.h>
#include<stdlib.h>

//declaration
struct Node{
    int data;
    struct Node* next;
};

//insert at start
struct Node* addstart(struct Node* head,int data){
    struct Node* ptr=malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;                      //new head return
}
//delete at start
struct Node* delstart(struct Node* head){
    struct Node* ptr=head;
    head=head->next;                    //head moved one step forward
    free(ptr);                  //ptr is at position of originl head
    return head;
}

//insert at post
struct Node* addpost(struct Node* head,int data,int post){
    struct Node* ptr=malloc(sizeof(struct Node));
    struct Node* point=head;
    int i=0;
    while(i!=post-1){                 //index not equal to input 
        point=point->next;
        i++;
    }
    ptr->data=data;
    ptr->next=point->next;            //ptr next is now point next 
    point->next=ptr;                  //point next is my ptr node
    return head;              //head not changed
}
//delete at post
struct Node* delpost(struct Node* head,int post){
    struct Node* a=head;
    struct Node* b=head->next;
    for(int i=0;i<post-1;i++){             //loop until given post
        a=a->next;
        b=b->next;
    }
    a->next=b->next;                       //b is now at post to delete
    free(b);
    return head;
}

//insert at end
struct Node* addend(struct Node* head,int data){
    struct Node* ptr=malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node* point=head;                  //traverse
    while(point->next!=NULL){
        point=point->next;
    }
    point->next=ptr;                          //point at end next is ptr node
    ptr->next=NULL;               //last should be NULL
    return head;
}
//delete at end
struct Node* delend(struct Node* head){
    struct Node* a=head;
    struct Node* b=head->next;
    while(b->next!=NULL){             //same as post just loop until NULL occoures
        a=a->next;
        b=b->next;
    }
    a->next=b->next;
    free(b);
    return head;
}

 int main(void){

    //creating structure nodes and memory allocation
    struct Node* head=malloc(sizeof(struct Node));
    struct Node* one=malloc(sizeof(struct Node));
    struct Node* two=malloc(sizeof(struct Node));

    //assigning value and creating link
    head->data=10;
    head->next=one;
    one->data=20;
    one->next=two;
    two->data=30;
    two->next=NULL;

    head=addstart(head,40);
    head=addpost(head,50,3);
    head=addend(head,60);
    head=delstart(head);
    head=delpost(head,4);
    head=delend(head);

    //printing linklist
    struct Node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
 }