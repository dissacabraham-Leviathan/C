#include <stdio.h>
#include <string.h>
#include <ctype.h>

char Stack[100]; int top=-1;

char pop(void){
    if(top==-1){
        printf("Stack underflow");
        return '\0';
    }
    return Stack[top--];
}

void push(char y){ Stack[++top]=y; }

int preced(char y){
    if(y=='+'||y=='-') return 1;
    else if(y=='*'||y=='/') return 2;
    else if(y=='^') return 3;
    return 0;
}

int main(){
    char eqn[100]; int i=0;

    printf("Infix to Postfix\n");
    printf("Enter your Equation : ");
    scanf("%s",eqn);

    while(eqn[i]!='\0'){
        if(isalnum(eqn[i])){
            printf("%c",eqn[i]);
        }
        else if(eqn[i]=='('){ push(eqn[i]); }
        else if(eqn[i]==')'){
            while(top!=-1 && Stack[top]!='(')
                printf("%c",pop());
            pop();
        }
        else{
            while(top!=-1 && preced(Stack[top])>=preced(eqn[i]))
                printf("%c",pop());
            push(eqn[i]);
        }
        i++;
    }

    while(top!=-1)
        printf("%c",pop());

    return 0;
}