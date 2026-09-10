#include <stdio.h>
int main(){
    int a[5];
    for(int i = 0; i<7; i++){
        printf("Nhap phan tu a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < 7; i++){
        printf("%d ", a[i]);
    }
}