#include <stdio.h>
#include <math.h>
int main(){
    int n,i=0;
    do{
        printf("Nhap so phan tu n: ");
        scanf("%d",&n);
    }while(n<=0);

    int arr[n];
    for(i=0;i<n;i++){
        printf("Nhap phan tu thu %d vao mang: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Cac phan tu trong mang: ");
    for (i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }printf("\n\n");

    int demsnt = 0;
    for(i=0;i<n;i++){
        int dem=0;
        if(arr[i]>10){
            for(int j = 1; j <= sqrt(arr[i]); j++){
                if(arr[i] % j == 0){
                    ++dem;
                    if(j != arr[i]/j){
                        ++dem;
                    }
                }
            }
        }
        if(dem == 2){
            demsnt++;   
        }
    }(demsnt != 0) ? printf("So phan tu la so nguyen to lon hon 10 la %d\n\n",demsnt) :  printf("Khong co so nguyen to nao trong day so lon hon 10\n\n");

    return 0;    
}