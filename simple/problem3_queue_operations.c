#include <stdio.h>
int front=-1,rear=-1;
int queue[50];

void enqueue(int data){
    if(front==-1) front=0;
    queue[++rear] = data;
}

int dequeue(){
   if(rear==front) printf("Queue is empty");
   else return queue[front++];
}

int main(){
    long long registerNo;
    int n = 0;
    
    printf("Enter your Register Number: ");
    scanf("%lld", &registerNo);

    long long temp = registerNo;
    while (temp > 0){
        enqueue(temp % 10);
        temp /= 10;
        ++n;       
    }

    for (int i=0;i<n/2;i++){
        int t = queue[i];
        queue[i] = queue[n-1- i];
        queue[n-1-i] = t;
    }

    for(int i=0;i<5;i++) printf("\tDequeued elements : %d\n",dequeue());

return 0;
}
