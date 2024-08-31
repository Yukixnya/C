#include<stdio.h>
#define size 10

int arr[size];

int top =-1;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == size -1;
}

void push(int num){
    if(isFull()){
        printf("Stack Overflow");
        return;
    }
    top++;
    arr[top]=num;
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow");
        return -1;
    }
    int num = arr[top];
    top--;
    return num;
}

int main(){
    int num,data,c=0;
    printf("1.push\n2.pop\n3.check slots\n4.exit");
    do{
        printf("\nenter choice: ");
        scanf("%d",&num);
        switch(num){
            case 1:
                printf("enter number: ");
                scanf("%d",&data);
                push(data);
                c++;
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("slots available : %d",size-c);
                break;
            case 4:
                printf("\n\tStack\n");

                while (!isEmpty()) {
                    printf("\t%d\n", pop());
                }
                printf("Exiting...");
                break;
        }
    }while(num != 5);

}
/*                              more compact version
#include<stdio.h>
#define n 10
int top=-1;
int arr[n];
void push(int data){
    if(top<n-1){
        arr[++top]=data;
    }
    else{
    printf("overflow");
    }
}
int pop(){
    if(top>=0){
        return arr[top--];
    }
    printf("underflow");
}
int main(void){
    push(10);
    push(20);
    push(30);
    pop();
    pop();
    
    while(top>=0){
        printf("%d ",pop());
    }
}
*/