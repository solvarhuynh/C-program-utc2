#include <stdio.h>
int main(){
    int n;
    printf("Nhap so phan tu can sap xep: ");
    scanf("%d",&n);
    int arr[n];
    for (int i =0;i<n;i++){
        printf("Nhap gia tri vao mang: ");
        scanf("%d",&arr[i]);
    }

    for (int i = 1;<n;i++){
        for (int j = 0;j<i;j++){
            if (arr[i]<arr[j]){
                int tmp = arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
}