#include <stdio.h>
int top = -1;
int stack[50];

void push(int data){
    stack[++top] = data;
}

int pop(){
   return stack[top--];
}

int main(){
    long long registerNo;
    int n = 0;
    
    printf("Enter your Register Number: ");
    scanf("%lld", &registerNo);
    
    int max=0,min = 0;

    long long temp = registerNo;
    while (temp > 0){
        push(temp % 10);
        temp /= 10;

        if(stack[top]>max) max=stack[n];
        if(stack[top]<min) min=stack[n];

        ++n;       
    }

    for (int i=0;i<n/2;i++){
        int t = stack[i];
        stack[i] = stack[n-1- i];
        stack[n-1-i] = t;
    }
    
    for(int i=0;i<5;i++) printf("\tpopped element : %d\n",pop());
    printf("\nMax = %d\nMin = %d",max,min);

return 0;
}