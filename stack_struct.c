#include <stdio.h>
#include <stdlib.h>

#define size 10

struct Stack {
    int arr[size];
    int top;
};

void define(struct Stack *s) {
    s->top = -1; 
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == size - 1;
}

void push(struct Stack *s, int num) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = num;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; 
    }
    return s->arr[s->top--];
}

int main(void) {
    struct Stack *s = malloc(sizeof(struct Stack));
    define(s); 

    int num,data,c=0;
    printf("1.push\n2.pop\n3.check slots\n5.exit");
    do{
        printf("\nenter choice: ");
        scanf("%d",&num);
        switch(num){
            case 1:
                printf("enter number: ");
                scanf("%d",&data);
                push(s,data);
                c++;
                break;
            case 2:
                pop(s);
                break;
            case 3:
                printf("slots available : %d",size-c);
                break;
            case 5:
                printf("Exiting...");
                break;
        }
    }while(num != 5);

    printf("\n\tStack\n");

    while (!isEmpty(s)) {
        printf("\t%d\n", pop(s));
    }

    free(s); 

}
