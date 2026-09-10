#include <stdio.h>
int main(){
    int don_gia,so_luong;
    printf("Nhap don gia: ");
    scanf("%d",&don_gia);
    printf("Nhap so luong: ");
    scanf("%d",&so_luong);
    int thanh_tien;
    float giam_gia=0.0;
    thanh_tien = so_luong * don_gia;
    if(thanh_tien > 100){
        giam_gia = thanh_tien * 0.03;
    }
    printf("Tong tien phai tra: %.2f",thanh_tien - giam_gia);
    return 0;
}