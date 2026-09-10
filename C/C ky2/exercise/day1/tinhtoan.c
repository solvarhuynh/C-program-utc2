#include <stdio.h>
#include <stdlib.h>
//ham nhap
void input(int *arr, int n){
    for(int i = 0; i<n; i++){
        printf("Enter arr[%d]: ", i+1);
        scanf("%d", arr+i);
    }
}
//ham tinh tong
int sumArr(int *arr, int n){
    int sum=0;
    for(int i = 0; i < n; i++){
        sum += *(arr + i);
    }
    return sum;
}
//ham tim gia tri lon nhat va nho nhat
void findMaxMin(int *arr, int n){
    int max, min;
    max = min = *arr;
    for(int i = 1; i < n; i++){
        if(max < *(arr + i))
            max = *(arr + i);
        if(min > *(arr + i))
            min = *(arr + i);
    }
    printf("Max = %d\nMin = %d",max,min);
}
//ham dem so phan tu chan nho hon phan tu x
int countEve(int *arr, int n, int x){
    int count = 0;
    for (int i = 0; i<n; i++){
        if(*(arr+i) % 2 == 0 && *(arr+i) < x)
            count++;
    }
    return count;
}
int main(){
    int n, x;
    printf("Enter n: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    //nhap
    input(arr,n);
    //tong mang
    printf("\nSum of Array: %d\n", sumArr(arr,n));
    //gia tri trung binh
    printf("Average of Array: %.2f\n",sumArr(arr,n)/(1.0*n));
    //max va min
    findMaxMin(arr,n);
    //nhap x 
    printf("\nEnter x: ");
    scanf("%d",&x);
    //dem so phan tu chan nho hon x
    printf("The number of even elements less than %d is %d",x,countEve(arr,n,x));
}
