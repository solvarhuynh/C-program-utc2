#include <stdio.h>
#include <math.h>
int primeNumberCheck(int n){
    if(n<2){
        return 0;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    printf("Enter N: ");
    scanf("%d",&n);
    (primeNumberCheck(n) == 0) ? printf("N is not a Prime number") : printf("N is a Prime number");
}