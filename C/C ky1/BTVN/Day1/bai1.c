#include <stdio.h>
#include <math.h>
int main(){
    float r,a,b;
    printf("Nhap so do ban kinh r cua duong tron tam O: ");
    scanf("%f",&r);
    printf("Nhap 2 he so a va b cua phuong trinh y = ax + b: ");
    scanf("%f%f",&a,&b);

    float A, B, C, delta,x1,y1,x2,y2;
    A = a*a+1;
    B = 2*a*b;
    C = b*b - r*r;
    delta = B*B-4*A*C;
    
    if (delta < 0){
        printf("Duong thang va duong tron khong co diem chung");
    }else if(delta ==0){
        printf("Duong thang va duong tron giao nhau tai 1 diem: x = %.2f; y = %.2f",-B/2*A,a*(-B/2*A)+b);
    }else{
        x1 = (-B+sqrt(delta))/(2*A);
        y1 = a*x1+b;
        x2 = (-B-sqrt(delta))/(2*A);
        y2 = a*x2+b;
        printf("Duong thang va duong tron giao nhau tai 2 diem:\nx = %.2f; y = %.2f\n",x1,y1);
        printf("x = %.2f; y = %.2f",x2,y2);
    }
    
    return 0;    
}