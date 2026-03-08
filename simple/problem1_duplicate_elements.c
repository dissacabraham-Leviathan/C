#include <stdio.h>

int main()
{
    long long registerNo;
    int arr[20],visited[20], n = 0,count =  0;
    
    printf("Enter your Register Number: ");
    scanf("%lld", &registerNo);
    
    long long temp = registerNo;
    while (temp > 0) {
        arr[n++] = temp % 10;
        temp /= 10;
    }
    int digit[10]={0,1,2,3,4,5,6,7,8,9};
    
    for(int i=0;i<10;i++)
    {
        int flag=0;
           for(int j=0;j<n;j++)
           {
            if(digit[i]==arr[j]) 
               { count++;
                flag=1; }
           }
        if(flag==1)
                count--;
    }
    
    printf("No.of Diplicate Elements is : %d",count);
    return 0;
}
 