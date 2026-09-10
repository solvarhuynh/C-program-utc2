#include <stdio.h>

int main() {
    char hovaten[20], gioitinh[10], truong[30];
    float toan, ly, hoa;
    printf("Nhập Họ Và Tên: ");
    fgets(hovaten,20,stdin);
    printf("Nhập Giới Tính: ");
    fgets(gioitinh,20,stdin);
    printf("Nhập Tên Trường: ");
    fgets(truong,20,stdin);
    fflush(stdin);
    
    printf("Nhập điểm Toán: ");
    scanf("%f", &toan);
    printf("Nhập điểm Lý: ");
    scanf("%f", &ly);
    printf("Nhập điểm Hóa: ");
    scanf("%f", &hoa);
    printf("Họ Và Tên: %s\nGiới Tính: %s\nTrường: %s\nĐiểm TB: %.2f\n",hovaten,gioitinh,truong,(toan+ly+hoa)/3);

    return 0; 
}
