#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *ten;
    int mssv;
    int ngaySinh;
    char *gioiTinh;
    char *diaChi;
} sv;
void nhap(sv *a);
void in(sv *a);

int main(){
    sv *a = malloc(sizeof(sv));
    a->ten = (char*)malloc(100 * sizeof(char));
    a->gioiTinh = (char*)malloc(10 * sizeof(char));
    a->diaChi = (char*)malloc(100 * sizeof(char));

    nhap(a);
    in(a);
}
void nhap(sv*a){
    printf("Nhap ten sinh vien: ");
    scanf("%[^\n]%*c",a->ten); 
    printf("Nhap MSSV: ");
    scanf("%d",a->mssv);
    printf("Nhap ngay sinh: ");
    scanf("%d",a->ngaySinh);
    printf("Nhap gioi tinh: ");
    scanf(" %s",a->gioiTinh);
    printf("Nhap dia chi: ");
    scanf("%[^\n]%*c",a->diaChi);
}
void in(sv*a){
    printf("\n======== Thong Tin Sinh Vien ========\n");
    printf("Ten: %s\n", a->ten);
    printf("MSSV: %d\n", a->mssv);
    printf("Ngay sinh: %d\n", a->ngaySinh);
    printf("Gioi tinh: %s\n", a->gioiTinh);
    printf("Dia chi: %s\n", a->diaChi);
}
