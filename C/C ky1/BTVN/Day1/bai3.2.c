#include <stdio.h>
#include <math.h>
int main(){
    float a1,b1,c1,a2,b2,c2,x,y;
    printf("Nhap he so a1, b1, c1 cua phuong trinh a1x + b1y = c1: ");
    scanf("%f%f%f",&a1,&b1,&c1);
    printf("Nhap he so a2, b2, c2 cua phuong trinh a2x + b2y = c2: ");
    scanf("%f%f%f",&a2,&b2,&c2);
    
    float ty_le=a1/a2;
    if (a1!= 0 && a2 != 0){ 
        a2 *= ty_le;
        b2 *= ty_le;
        c2 *= ty_le;
        b2 -= b1;
        c2 -= c1;
    
        if (b2 == 0){
            printf(c2 == 0 ? "He phuong trinh vo so nghiem":"He phuong trinh vo nghiem");
        }else{
            y = c2/b2;
            x = (c1-(b1*c2)/b2)/a1;
            printf("He phuong trinh co 2 nghiem x = %.1f va y = %.1f",x,y);
        }

    }else if (a1 == 0 && a2 != 0){
        if (b1 == 0){
            printf(c1 == 0 ? "He phuong trinh vo so nghiem":"He phuong trinh vo nghiem");
        }else{
            y = c1/b1;
            x = (c2-(b2*c1)/b1)/a2;
            printf("He phuong trinh co 2 nghiem x = %.1f va y = %.1f",x,y);
        }

    }else if (a1 != 0 && a2 == 0){
        if (b2 == 0){
            printf(c2 == 0 ? "He phuong trinh vo so nghiem":"He phuong trinh vo nghiem");
        }else{
            y = c2/b2;
            x = (c1-(b1*c2)/b2)/a1;
            printf("He phuong trinh co 2 nghiem x = %.1f va y = %.1f",x,y);
        }
        
    }else if (b1 == 0 && b2 == 0){
            if (c1 == 0 && c2 == 0){
                printf("He phuong trinh vo so nghiem");
            }else{
                printf("He phuong trinh vo nghiem");
            }
        }else if(b1 == 0 && b2 != 0){
            if(c1 == 0){
                y=c2/b2;
                printf("He phuong trinh co 1 nghiem y = %.2f va x tuy y",y);
            }else{
                printf("He phuong trinh vo nghiem");
            }
        }else if(b1 != 0 && b2 == 0){
            if(c2 == 0){
                y=c1/b1;
                printf("He phuong trinh co 1 nghiem y = %.2f va x tuy y",y);
            }else{
                printf("He phuong trinh vo nghiem");
            }
    }    
}