#include <stdio.h>
#include <stdlib.h>
void enter(float **arr, int *n){
    printf("Nhap cap cua ma tran vuong: ");
    scanf("%d",n);
    *arr = (float*)malloc((*n)*(*n)*sizeof(float));
    for(int i = 0; i < *n; i++){
        for(int j = 0; j < *n; j++){
            printf("Nhap phan tu thu [%d][%d]: ",i+1,j+1);
            scanf("%f",(*arr+(i*3+j)));
        }
    }
}
float tongMaTran(float *arr, int n){
    float sum = 0;
    for(int i = 0; i<n*n; i++)
        sum += *(arr+i);
    return sum;
}
float maxOfmatrix(float *arr, int n){
    float max = *arr;
    for(int i = 1; i<n*n; i++){
        if(max<*(arr+i))
            max = *(arr+i);
    }
    return max;
}
void minTichCot(float *arr, int n){ //sua lai ham void
    float tmp[n];
    for(int i = 0; i<n; i++){
        float tich = 1;
        for(int j = 0; j<n; j++){
            tich *= *(arr + i+3*j);
        }
        tmp[i] = tich;
    }
    float min = tmp[0];
    for(int i = 1; i<n; i++){
        if(min > tmp[i])
            min = tmp[i];
    }

    printf("\nCot co tich nho nhat la cot thu %d voi tich = %.2f\n");
}
int main(){
    int n;
    float *arr;
    enter(&arr,&n);
    printf("\nTong ma tran = %.2f\n",tongMaTran(arr,n));
    printf("\nMax cua ma tran = %.2f\n",maxOfmatrix(arr,n));

}