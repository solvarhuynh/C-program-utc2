#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int tu;
    int mau;
} PS;

PS nhapPS(){
    PS ps;
    printf("Nhap tu so: ");
    scanf("%d", &ps.tu);
    do{
        printf("Nhap mau so (!= 0): ");
        scanf("%d", &ps.mau);
        if(ps.mau == 0)
            printf("Loi! hay nhap lai\n");
    } while(ps.mau == 0);
    return ps;
}
void inPS(PS ps){
    printf("%d/%d  ", ps.tu, ps.mau);
}
int ucln(int a, int b){ //uoc chung cua mau so va tu so
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int bcnn(int a, int b){ //cung la boi chung cua tu va mau so???
    return (a*b)/ucln(a,b);
}
PS rutGon(PS ps){
    if(ps.mau < 0){
        ps.tu = -ps.tu; ps.mau = -ps.mau;
    }
    int u = ucln(abs(ps.tu), abs(ps.mau));
    if(u != 0){
        ps.tu /= u; ps.mau /= u;
    }return ps;
}
PS cong(PS ps1, PS ps2){
    PS kq;
    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    return rutGon(kq);
}
PS tru(PS ps1, PS ps2){
    PS kq;
    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    return rutGon(kq);
}
PS nhan(PS ps1, PS ps2){
    PS kq;
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    return rutGon(kq);
}
PS chia(PS ps1, PS ps2){
    PS kq;
    kq.tu = ps1.tu * ps2.mau;
    kq.mau = ps1.mau * ps2.tu;
    return rutGon(kq);
}
int soSanh(PS ps1, PS ps2){
    int tu1 = ps1.tu * ps2.mau;
    int tu2 = ps2.tu * ps1.mau;
    if(tu1 > tu2)
        return 1;
    else if(tu1 < tu2)
        return -1;
    else
        return 0;
}
void nhapDayPS(PS *arr, int n){
    for (int i = 0; i < n; i++){
        printf("Phan so %d:\n", i+1);
        *(arr + i) = nhapPS();
    }
}
void inDayPS(PS *arr, int n){
    for (int i = 0; i < n; i++){
        inPS(*(arr + i));
    }printf("\n");
}
int timMaxPS(PS *arr, int n){
    int index = 0;
    for (int i = 1; i < n; i++){
        if(soSanh(arr[i], arr[index]) > 0)
            index = i;
    }
    return index;
}
int timKiemPS(PS *arr, int n, PS target){
    for (int i = 0; i < n; i++){
        if(soSanh(rutGon(arr[i]), rutGon(target)) == 0)
            return i+1;
    }    return -1;
}
void sapXepPS(PS *arr, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if(soSanh(arr[i], arr[j]) > 0){
                PS temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }    
    }
}
PS tinhTongDay(PS *arr, int n){
    PS sum;
    sum.tu = 0;
    sum.mau = 1;
    for (int i = 0; i < n; i++){
        sum = cong(sum, arr[i]);
    }    return sum;
}
int main(){
    int n;
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    PS *ds = (PS *)malloc(n * sizeof(PS));
    if(ds == NULL){
        printf("Khong the cap phat bo nho!\n");
        return 1;
    }
    nhapDayPS(ds, n);

    printf("\nDay phan so vua nhap:\n");
    inDayPS(ds, n);

    for(int i = 0; i < n; i++){
        ds[i] = rutGon(ds[i]);
    }    printf("\nDay phan so sau khi rut gon:\n");
    inDayPS(ds, n);

    if(n >= 2){
        PS ps1 = ds[0], ps2 = ds[1];
        printf("\nCong: ");
        inPS(cong(ps1, ps2));
        printf("\nTru: ");
        inPS(tru(ps1, ps2));
        printf("\nNhan: ");
        inPS(nhan(ps1, ps2));
        printf("\nChia: ");
        inPS(chia(ps1, ps2));
        printf("\n");
    }
    if(n >= 2){
        int kq = soSanh(ds[0], ds[1]);
        printf("\nSo sanh 2 phan so dau tien: ");
        if(kq > 0)
            printf("Phan so 1 > Phan so 2\n");
        else if(kq < 0)
            printf("Phan so 1 < Phan so 2\n");
        else
            printf("Phan so 1 = Phan so 2\n");
    }
    int idxMax = timMaxPS(ds, n);
    printf("\nPhan so lon nhat la: ");
    inPS(ds[idxMax]);
    printf("\n");

    PS tim;
    printf("\nNhap phan so can tim (tu mau): ");
    scanf("%d%d", &tim.tu, &tim.mau);
    tim = rutGon(tim);
    int pos = timKiemPS(ds, n, tim);
    if(pos != -1)
        printf("Phan so vua nhap co trong day tai vi tri %d\n", pos);
    else
        printf("Khong tim thay phan so vua nhap trong day.\n");

    sapXepPS(ds, n);
    printf("\nDay phan so sau khi sap xep:\n");
    inDayPS(ds, n);

    PS tong = tinhTongDay(ds, n);
    printf("\nTong cac phan so trong day la: ");
    inPS(tong);
    printf("\n");

    free(ds);
    return 0;
}