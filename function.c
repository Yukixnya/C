//create linklist

#include<stdio.h>
#include<stdlib.h>

//declaration
struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;  //global declaration of head

//create function
void create(int data){
    struct Node* node;
    node=malloc(sizeof(struct Node));
    if(node==NULL){
        printf("Empty List");
        return;
    }
    node->data=data;
    node->next=head; // Make the new node point to the current head
    head=node;  // Set the new node as the head
}

//print function
void print(){
    struct Node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
};

 int main(void){
    create(10);
    create(20);
    create(30);
    print();
 }