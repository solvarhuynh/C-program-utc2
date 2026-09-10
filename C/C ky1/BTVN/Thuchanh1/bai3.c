#include <stdio.h>
int UCLN(int a, int b){
    while(b!=0){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    int a,b;
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);

    int ucln = UCLN(a,b);
    printf("UCLN is: %d\n",ucln);
    printf("BCNN is: %d",a*b/ucln);
}