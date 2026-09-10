#include <stdio.h>
int factorial(int n){
    if(n == 1){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}
// int factorial(int n){
//     int s = 1;
//     for(int i=n; i>=2; i--){
//         s *= i;
//     }
//     return s;
// }

int main(){
    int n;
    do{
        printf("Enter n: ");
        scanf("%d",&n);
    }while(n<=0);
    
    printf("The factorielle of %d is: %d",n,factorial(n));
}