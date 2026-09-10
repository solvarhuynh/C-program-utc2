#include <stdio.h>
#include <string.h>

//kieu du lieu nhan vien
typedef struct NhanVien{
    char maNV[10];
    char hoTen[30];
    int luongCoBan;
    int phuCap;
    int tongLuong;
}nv;
//kieu du lieu phong ban
typedef struct PhongBan{
    char maPB[10];
    char tenPB[20];
    int soLuongNV;
    nv dsNhanVien[100];
}pb;
//nhap thong tin nhan vien
void inputNhanVien(nv *nhanVien){
    printf("Nhap ma nhan vien: ");
    scanf("%[^\n]", nhanVien->maNV);
    getchar();
    printf("Nhap ho va ten nhan vien: ");
    scanf("%[^\n]", nhanVien->hoTen);
    printf("Nhap luong co ban: ");
    scanf("%d", &nhanVien->luongCoBan);
    printf("Nhap luong phu cap: ");
    scanf("%d", &nhanVien->phuCap);
    nhanVien->tongLuong = nhanVien->luongCoBan + nhanVien->phuCap;
}
//nhap thong tin cac phong ban
void inputDSPhongBan(pb phongBan[], int n){
    for(int i = 0; i < n; i++){
        getchar();
        printf("\n========= Nhap thong tin phong ban thu %d =========\n",i+1);
        printf("Nhap ma phong ban: ");
        scanf("%[^\n]", phongBan[i].maPB);
        getchar();
        printf("Nhap ten phong ban: ");
        scanf("%[^\n]", phongBan[i].tenPB);
        
        do{
            printf("Nhap so luong nhan vien: ");
            scanf("%d", &phongBan[i].soLuongNV);
            if(phongBan[i].soLuongNV<=0)
                printf("Vui long nhap so luong nhan vien > 0\n");
        }while(phongBan[i].soLuongNV<=0);
        
        for(int j = 0; j < phongBan[i].soLuongNV; j++){
            printf("\n======= Nhap thong tin nhan vien thu %d =======\n", j+1);
            getchar();
            inputNhanVien(&phongBan[i].dsNhanVien[j]);
        }
    }
}
//xuat thong tin 1 nhan vien
void outputNhanVien(nv nhanVien){
    printf("Ma nhan vien: %s\n", nhanVien.maNV);
    printf("Ten nhan vien: %s\n", nhanVien.hoTen);
    printf("Luong co ban: %d\n", nhanVien.luongCoBan);
    printf("Luong phu cap: %d\n", nhanVien.phuCap);
    printf("Tong luong: %d\n", nhanVien.tongLuong);
}
//xuat thong tin 1 phong ban
void outputPhongBan(pb phongBan){
    printf("Ma phong ban: %s\n", phongBan.maPB);
    printf("Ten phong ban: %s\n", phongBan.tenPB);
    printf("So luong nhan vien: %d\n", phongBan.soLuongNV);
    for(int i = 0; i < phongBan.soLuongNV; i++){
        printf("\nThong tin nhan vien thu %d\n", i+1);
        outputNhanVien(phongBan.dsNhanVien[i]);
    }
}
//xuat thong tin cac phong ban
void printPhongBan(pb phongBan[], int n){
    for(int i = 0; i<n; i++){
        printf("\n======== THONG TIN %s ========\n", strupr(phongBan[i].tenPB));
        outputPhongBan(phongBan[i]);
    }
}
//tong luong toan bo nhan vien 1 phong ban 
int tongluongPB(pb phongBan){
    int sum = 0;
    for(int i = 0; i < phongBan.soLuongNV; i++){
        sum += phongBan.dsNhanVien[i].tongLuong;
    }
    return sum;
}
//tim kiem nhan vien theo ma nhan vien
nv *findNV(pb phongBan[], int n, char msnv[20]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < phongBan[i].soLuongNV; j++){
            if(strcmp(phongBan[i].dsNhanVien[j].maNV,msnv) == 0)
                return &phongBan[i].dsNhanVien[j];
        }
    }
    return NULL;
}
//tim kiem nhan vien co luong cao nhat trong cong ty
nv *findMaxOfTL(pb phongBan[], int n){
    int maxTL = phongBan[0].dsNhanVien[0].tongLuong;
    nv *maxTLOfNV = &phongBan[0].dsNhanVien[0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < phongBan[i].soLuongNV; j++){
            if(maxTL < phongBan[i].dsNhanVien[j].tongLuong){
                maxTL = phongBan[i].dsNhanVien[j].tongLuong;
                maxTLOfNV = &phongBan[i].dsNhanVien[j];
            }
        }
    }
    return maxTLOfNV;
}
//Menu
void Menu(){
    printf("\n========== THONG TIN CONG TY ==========\n");
    printf("1. Xuat thong tin cac phong ban.\n");
    printf("2. Tinh toan tong luong cua cong ty.\n");
    printf("3. Tim kiem nhan vien theo ma so nv.\n");
    printf("4. Tim nhan vien co tong luong cao nhat.\n");
    printf("5. Thoat.\n");
    printf("\nMoi nhap lua chon: ");
}

int main(){
    //khai bao so phong ban 
    int n;
    //nhap so nhan vien
    do{
        printf("Nhap so luong phong ban: ");
        scanf("%d", &n);
        if(n<=0)
            printf("Vui long nhap so luong nhan vien > 0\n");
    }while(n<=0);
    //khai bao phong ban co kieu du lieu la struct pb
    pb phongBan[n];
    //nhap thong tin phong ban
    inputDSPhongBan(phongBan, n);
    //khai bao lua chon
    int choice;
    do{
        Menu;
        scanf("%d",&choice);
        switch (choice){
            case 1:
                //xuat thong tin phong ban
                printPhongBan(phongBan, n);
                break;
            case 2:
                //tong luong cua nhan vien trong 1 phong ban
                for(int i = 0; i<n; i++){
                    printf("\nTong luong cua toan bo nhan vien trong %s la: %d\n",phongBan[i].tenPB,tongluongPB(phongBan[i]));
                }
                break;
            case 3:
                //nhap ma nv
                char msnv[20];
                getchar();
                printf("Nhap ma so nhan vien can tim: ");
                scanf("%s",msnv);
                //tim kiem nhan vien theo ma nhan vien
                nv *result = findNV(phongBan, n, msnv);
                if(result != NULL){
                    printf("Nhan vien co msnv %s la::\n",msnv);
                    outputNhanVien(*result);
                }else{
                    printf("Khong co ma so nhan vien nay!\n");
                }
                break;
            case 4:
                //tim nhan vien co tong luong cao nhat
                printf("Nhan vien co tong luong cao nhat cong ty la:\n");
                outputNhanVien(*findMaxOfTL(phongBan, n));
                break;
            case 5:
                break;
            default: printf("Vui long nhap lai lua chon!\n");
        }
    }while(choice != 5);
}

