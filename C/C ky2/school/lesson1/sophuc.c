#include <stdio.h>
typedef struct{
    float thuc, ao;
}soPhuc;

soPhuc tongSoPhuc(soPhuc a, soPhuc b);
soPhuc tichSoPhuc(soPhuc a, soPhuc b);

int main(){
    soPhuc a,b,tmp1, tmp2;
    printf("Nhap cap so a, b cua so phuc a + bi: ");
    scanf("%f%f",&a.thuc,&a.ao);
    printf("Nhap cap so c, d cua so phuc c + di: ");
    scanf("%f%f",&b.thuc,&b.ao);
    tmp1 = tongSoPhuc(a,b);
    tmp2 = tichSoPhuc(a,b);
    printf("Tong 2 so phuc: %.1f + %.1fi\nTich 2 so phuc: %.1f + %.1fi",tmp1.thuc, tmp1.ao, tmp2.thuc, tmp2.ao);
}
soPhuc tongSoPhuc(soPhuc a, soPhuc b){
    soPhuc tong;
    tong.thuc = a.thuc + b.thuc;
    tong.ao = a.ao + b.ao;
    return tong;
}
soPhuc tichSoPhuc(soPhuc a, soPhuc b){
    soPhuc tich;
    tich.thuc = a.thuc*b.thuc - a.ao*b.ao;
    tich.ao = a.thuc*b.ao + a.ao*b.thuc;
    return tich;
}