///@brief infix to postfix conversion
///@param push insert data
///@param pop retrive data
///@param oper set of ooperators
///@param rank priority defining
///@param conv conversion from infix to postfix
#include<stdio.h>
#include<ctype.h>
#define n 30

char arr[n];
int top=-1;

void push(char data){
    if(top==n-1){
        printf("overflow");
    }
    arr[++top]=data;
}

char pop(){
    if(top>=0){
        return arr[top--];  
    }
    return '\0';
}

/// @brief for veryfing operators
/// @param data operators
/// @return 1->result is operator
/// @return 0->result is operand
int oper(char data){                                             
    if(data=='+' || data=='-' || data=='*' || data=='^' || data=='/'){
        return 1;                   
    }
    return 0;                       
}
/// @brief ranking system   ...  preceeding values
/// @return 1->lowest 2->mid 3->highest
int rank(char data){                                      
    if(data=='+' || data=='-'){
        return 1;
    }
    else if(data=='*' || data=='/'){
        return 2;
    }
    else if(data=='^'){
        return 3;
    }
    return 0;
}
/// @brief TOH like conversion function
/// @param ele temp variable helping in transfer from infix stack to postfix stack
void conv(char infix[],char post[]){                      
    int i=0,p=0;                               //as traversing pointers
    while (infix[i]!='\0'){      //not equals to null           
        char ele = infix[i];                   //tempory storing element of infix in ele
        if(isalnum(ele)){          //num checking                                     //num also an operand
            post[p++]=ele;                    //adding ele in postfix     // cause we need only operands
        }
        else if(ele=='('){                 
            push(ele);                      //if open then push in stack
        }
        else if(ele==')'){                 //until ele not ) brackets will not complete
            char popele = pop();                                  //store ele in popele
            while(popele!='('){       //if ( then terminate so                                     //conditon is !=(
                post[p]= popele;                               //adding value of popele to postfix
                p++;
                popele = pop();             //remove old assigned value of popele
            }
        }
        else if(oper(ele)){
            while(top>0 && rank(arr[top]) >= rank(ele)){      //i.e 2 on 1 not 1 on 2 ranking check and function
                post[p]=pop();                                      //adding value in post ...operands
                p++;
            }
            push(ele);                  //dont forget to push ele back       //adding operators in stack
        }
        i++;             //i should be incremented in while loop
    }
    while(top>=0){
        post[p]=pop();
        p++;
    }
    post[p]='\0';            //just in case for understanding...
}

/// @param post stack 
/// @param infix stack
/// @param conv infix to postfix 
int main(void){
    char post[n];         
    char infix[n];       
    printf("enter expression : ");
    scanf("%s",infix);
    conv(infix,post);
    printf("postfix expression : %s",post);
}