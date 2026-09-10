#include <stdio.h>

float giai(int n, float x){
    float sum = 2;
    for(int i = 1; i <= n; i++){
        sum += (x + 2*i + 1)/(2*i + 7);
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