#include <stdio.h>
#include <math.h>

typedef struct{
    float x, y;
} diem;

float khoanCach(diem a, diem b);
int xetTamGiac(float a, float b, float c);
float dienTich(float a, float b, float c);

int main(){
    diem A,B,C;
    printf("Nhap diem A: "); scanf("%f%f",&A.x,&A.y);
    printf("Nhap diem B: "); scanf("%f%f",&B.x,&B.y);
    printf("Nhap diem C: "); scanf("%f%f",&C.x,&C.y);
    float AB = khoanCach(A,B),BC = khoanCach(B,C),CA = khoanCach(C,A);
    if(xetTamGiac(AB,BC,CA)){
        printf("3 diem tao thanh tam giac\nChu vi: %.2f\nDien tich: %.2f\n",AB+BC+CA, dienTich(AB,BC,CA));
    } else {
        printf("3 diem khong tao thanh tam giac\n");
    }
}
float khoanCach(diem a, diem b){
    return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
}

int xetTamGiac(float a, float b, float c){
    return (a+b>c)&&(a+c>b)&&(b + c > a);
}

float dienTich(float a, float b, float c){
    float p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}