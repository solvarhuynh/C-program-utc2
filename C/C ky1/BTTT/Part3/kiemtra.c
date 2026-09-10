#include <stdio.h>
#include <math.h>
int main(){
    int n;
    printf("Nhap so phan tu n: ");
    scanf("%d",&n);

    int arr[n], dem = 0;
    for(int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d vao mang: ",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i = 0;i<n;i++){
        if(arr[i] < 2){
            dem++;
        }
        else{
            for(int j = 2; j <= sqrt(arr[i]); j++){
                if(arr[i] % j == 0){
                    dem++;
                    break;
                }
            }
        }
    }
    (dem == 0)?printf("Day khong co snt") : printf("Day co %d snt", n - dem);
}
