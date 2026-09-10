#include <stdio.h>
int sum(int n){
    int s = 0;
    for(int i = 0; i<=n; i++){
        s += i*2 + 1;
    }
    return s;
}
int main(){
    int n;
    do{
        printf("Enter n: ");
        scanf("%d",&n);
    }while(n<=0);

    printf("The sum of the first %d odd number is: %d",n,sum(n));
}