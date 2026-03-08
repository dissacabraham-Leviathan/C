#include <stdio.h>

int fibo(int n) {
    if (n <= 1)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n;
    
    printf("enter n : ");
    scanf("%d", &n);
    
    printf("\nFibonacci Series : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibo(i));
    }
    printf("\n");
    
    return 0;
}
