#include <stdio.h>
#include <stdlib.h>
void nhap(int **arr, int *n){
    printf("Nhap so phan tu: "); scanf("%d", n);
    *arr = (int*)malloc(*n *sizeof(int));
    for(int i = 0; i<*n; i++){
        printf("Nhap phan tu thu %d: ",i+1);
        scanf("%d", *arr+i);
    }
}
int tong(int *arr, int n){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += *(arr+i);
    }
    return sum;
}
void xuat(int *arr, int n){
    printf("\nCac phan tu trong mang:\n");
    for(int i = 0; i<n; i++){
        printf("%d ",*(arr+i));
    }
}
int main(){
    int *arr, n;
    nhap(&arr,&n);
    xuat(arr,n);
    printf("\nTong mang: %d", tong(arr,n));
}