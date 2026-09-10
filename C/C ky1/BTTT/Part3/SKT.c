#include <stdio.h>
#include <math.h>
void import(int arr[], int n){
    for(int i = 0; i<n; i++){
        printf("Nhap phan tu thu %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}