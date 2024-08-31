#include<stdio.h>
#define size 10

int arr[size];

int  front= 0;
int rear = -1;

int isEmpty(){
    return front>rear;
}

int isFull(){
    return rear == size-1;
}

void enqueue(int num){
    if(isFull()){
        printf("Queue is full");
        return;
    }
    arr[++rear]=num;
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is empty");
        return -1;
    } 
    return arr[front++];
}

int main(){
    int num,data,c=0;
    printf("1.enqueue\n2.dequeue\n3.check slots\n4.exit");
    do{
        printf("\nenter choice: ");
        scanf("%d",&num);
        switch(num){
            case 1:
                printf("enter number: ");
                scanf("%d",&data);
                enqueue(data);
                c++;
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("slots available : %d",size-c);
                break;
            case 4:
                printf("\n\tQueue : ");

                while (!isEmpty()) {
                    printf("%d  ", dequeue());
                }
                printf("\nExiting...");
                break;
        }
    }while(num != 4);
}

/*                                more compact version
#include<stdio.h>
#define n 10
int front=0;
int rear=-1;
int arr[n];
void push(int data){
    if(front<n-1){
        arr[++rear]=data;
    }
    else{
    printf("overflow");
    }
}
int pop(){
    if(rear>=0){
        return arr[front++];
    }
    printf("underflow");
    return -1;
}
int main(void){
    push(10);
    push(20);
    push(30);
    pop();
    pop();
    
    while(front<=rear){
        printf("%d ",pop());
    }
}
*/