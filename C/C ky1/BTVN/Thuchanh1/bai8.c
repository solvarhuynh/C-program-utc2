#include <stdio.h>
int sum(int n){
    int s = 0;
    for(int i=1; i<=n; i++){
        s += i*i*i;
    }
    return s;
}
int main(){
    int n;
    do{
        printf("Enter n: ");
        scanf("%d",&n);
    }while(n<=0);
    
    printf("The sum of the series from 1^3 to %d^3 is: %d",n,sum(n));
}