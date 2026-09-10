#include <stdio.h>
#include <math.h>
int main(){
    float N,X;
    printf("Nhap so nguyen X va can bac N: ");
    scanf("%f%f",&X,&N);

    if(X>=0){
        printf("%.2f can bac %.2f = %.2f",X,N,pow(X,1/N));
    }else{
        printf("Hay nhap X lon hon hoac bang 0");
    }

    return 0;
}