#include <stdio.h>
int sum(int n){
    int s = 0;
    for(int i=1; i<=n; i++){
        s += i*(i+1)*(i+2);
    }
    return s;
}
int main(){
    int n;
    do{
        printf("Enter n: ");
        scanf("%d",&n);
    }while(n<=0);

    printf("The sum of the series from 1*2*3 to %d*%d*%d is: %d",n,n+1,n+2,sum(n));
}