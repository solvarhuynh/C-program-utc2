#include<stdio.h>
int sum(int n){
    int s = 0;
    for(int i = 1; i<=n; i++){
        s += i*2;
    }
    return s;
}
int main(){
    int n;
    do{
        printf("Enter n: ");
        scanf("%d",&n);
    }while (n<=0);

    printf("The sum of the first %d even number is: %d",n,sum(n));
}