#include <stdio.h>

//nhap cac phan tu vao mang 2 chieu
void inputArray(int arr[][100], int m, int n){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("Enter array[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}
//Xuat mang 2 chieu
void outputArray(int arr[][100], int m, int n){
    printf("\nThe 2D array is:\n");
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
//tim min max cua mang 2 chieu
void minMaxInArray(int arr[][100], int m, int n){
    int min = arr[0][0], max = arr[0][0]; 
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(arr[i][j] > max)
                max = arr[i][j];
            if(arr[i][j] < min)
                min = arr[i][j];
        }
    }
    printf("The minimum value of the 2D array is: %d\n", min);
    printf("The maximum value of the 2D array is: %d\n", max);
}
int main(){
    //khai bao mang 2 chieu gom 100 hang va 100 cot, m hang va n cot
    int arr[100][100], m, n;
    //nhap m hang va n cot
    do{
        printf("Enter m and n: ");
        scanf("%d%d",&m,&n);
    }while(m<=0 || n<=0);
    //nhap mang 2 chieu
    inputArray(arr,m,n);
    //xuat mang 2 chieu
    outputArray(arr,m,n);
    //tim min max cua mang 2 chieu
    minMaxInArray(arr,m,n);
}