#include <stdio.h>
#include <math.h>

float giai(int n, float x){
    float sum = 2;
    for(int i = 1; i <= n; i++){
        sum += (1 + pow(x,i)) / (i + 1);
    }
    return sum;
}

int main(){
    int n;
    float x;
    do{
        printf("Nhap so nguyen duong n: ");
        scanf("%d",&n);
    }while(n<=0);
    printf("Nhap so thuc x: ");
    scanf("%f",&x);
    
    printf("Dap an la: %.2f",giai(n,x));
    
}