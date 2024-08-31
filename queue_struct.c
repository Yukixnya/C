#include<stdio.h>
#include<stdlib.h>
#define size 10

struct Queue {
    int arr[size];
    int front;
    int rear;
};

void define(struct Queue *q) {
    q->front = 0;
    q->rear = -1; 
}

int isEmpty(struct Queue *q) {
    return q->front>q->rear;
}

int isFull(struct Queue *q) {
    return q->rear == size - 1;
}

void enqueue(struct Queue *q,int num){
    if(isFull(q)){
        printf("Stack Overflow");
        return;
    }
    q->arr[++q->rear] = num;
    
}

int dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Stack Underflow");
        return -1;
    }

    return q->arr[q->front++];
}

int main(){
    struct Queue *q = malloc(sizeof(struct Queue));
    define(q); 

    int num,data,c=0;
    printf("1.enqueue\n2.dequeue\n3.check slots\n5.exit");
    do{
        printf("\nenter choice: ");
        scanf("%d",&num);
        switch(num){
            case 1:
                printf("enter number: ");
                scanf("%d",&data);
                enqueue(q,data);
                c++;
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                printf("slots available : %d",size-c);
                break;
            case 5:
                printf("\n\tQueue\n");

                while (!isEmpty(q)) {
                    printf("\t%d\n", dequeue(q));
                }
                printf("Exiting...");
                break;
        }
    }while(num != 5);
}