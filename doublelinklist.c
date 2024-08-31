//create doubly linklist

#include<stdio.h>
#include<stdlib.h>

//declaration
struct Node{
    int data;
    struct Node* next;
    struct Node* back;
};


//insert at start
struct Node* addstart(struct Node* head,int data){
    struct Node* ptr=malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->back = NULL;  // New node's previous points to NULL
    ptr->next = head;  // New node's next points to the current head                     
    if (head != NULL) {
        head->back = ptr;  // Update previous of the current head to point to the new node
    }
    head=ptr;
    return ptr;//new head return
}
//delete at start
struct Node* delstart(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* ptr = head->next;  // Get the next node as the new head

    if (ptr != NULL) {
        ptr->back = NULL;  // Update the new head's previous pointer to NULL
    }

    free(head);  // Free memory of the deleted node
    return ptr;  // Return the new head
}

//insert at end
struct Node* addend(struct Node* head, int data) {
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->back = NULL;

    if (head == NULL) {
        return ptr; // If list is empty, new node becomes head
    }

    struct Node* point = head;
    while (point->next != NULL) {
        point = point->next; // Traverse to the end of the list
    }
  
    point->next = ptr; // Append new node after the last node
    ptr->back = point; // Update new node's previous pointer

    return head; // Return the head of the list
}

//delete at end
struct Node* delend(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL) { // If there's only one node in the list
        free(head);
        return NULL;
    }

    struct Node* point = head;
    while (point->next != NULL) {
        point = point->next; // Traverse to the end of the list
    }

    if (point->back != NULL) {
        point->back->next = NULL; // Set the next pointer of the second-to-last node to NULL
    }

    free(point); // Free memory of the last node
    return head; // Return the head of the list
}

 int main(void){

    //creating structure nodes and memory allocation
    struct Node* head=malloc(sizeof(struct Node));
    struct Node* one=malloc(sizeof(struct Node));
    struct Node* two=malloc(sizeof(struct Node));

    //assigning value and creating link
    head->back=NULL;
    head->data=10;
    head->next=one;

    one->back=head;
    one->data=20;
    one->next=two;

    two->back=one;
    two->data=30;
    two->next=NULL;

    head=addstart(head,40);
    // head=addpost(head,50,3);
    head=addend(head,60);
    head=delstart(head);
    // head=delpost(head,4);
    head=delend(head);

    //printing linklist
    struct Node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
 }