#include <stdio.h>
#include <math.h>
int main(){
    float a1,b1,c1,a2,b2,c2,x,y;
    printf("Nhap he so a1, b1, c1 cua phuong trinh a1x + b1y = c1: ");
    scanf("%f%f%f",&a1,&b1,&c1);
    printf("Nhap he so a2, b2, c2 cua phuong trinh a2x + b2y = c2: ");
    scanf("%f%f%f",&a2,&b2,&c2);

    float det,detx,dety;
    det = a1*b2-a2*b1;
    detx = c1*b2-c2*b1;
    dety = a1*c2-a2*c1;

    if(det ==0){
        if(detx != 0 || dety != 0){
            printf("He phuong trinh vo nghiem");
        }else{
            printf("He phuong trinh vo so nghiem");
        }
    }else {
        x = detx/det;
        y = dety/det;
        printf("He phuong trinh co 2 nghiem x = %.1f va y = %.1f",x,y);
    }
}