#include <stdio.h>
#include <stdlib.h>
//a. ham nhap vao day n so thuc
int nhap(float **a){
    int n;
    printf("Nhap so phan tu: "); scanf("%d",&n);
    *a = (float *)malloc(n*sizeof(float));
    for(int i = 0; i<n; i++){
        printf("Nhap phan tu thu %d: ", i+1); scanf("%f",*a+i);
    }
    return n;
}
//b. ham tim max cua nhung phan tu duong neu co
int MaxDuong(int n, float *a, float *max){
    int cond = 0;
    *max = *a;
    for(int i = 1; i<n; i++){
        if(*(a+i) > 0 && *max < *(a+i)){
            *max = *(a+i);
            cond = 1;
        }
    }
    return cond;
}
//c. ham kiem tra day co tinh chat Fibonacy khong
int Fibo(int n, float *a){
    int cond = 1;
    for(int i = 2; i<n; i++){
        if(*(a+i) != *(a+i-1) + *(a+i-2)){
            cond = 0; break;
        }
    }
    return cond;
}
