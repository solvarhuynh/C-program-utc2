#include <stdio.h>
float sum(int n){
    float s = 0;
    for(int i=2; i<=n; i++){
        s += 1.0/(i*(i+1));
    }
    return s;
}
int main(){
    int n;
    do{
        printf("Enter n: ");
        scanf("%d",&n);
    }while(n<=0);

    printf("The sum of the series from 1/(2*3) to 1/(%d*%d) is: %.2f",n,n+1,sum(n));
}