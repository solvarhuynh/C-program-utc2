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

    int dem = 0;
    for(i = 0;i<n;i++){
        if(arr[i]<0){
            dem++;
        }
    }
    printf("So phan tu am trong mang la: %d\n\n",dem);

    int x;
    dem = 0;
    printf("Nhap so x can xet so cap so trong day so co tong bang x: ");
    scanf("%d",&x);
    for(i = 0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i]+arr[j]) == x){
                dem++;
            }
        }
    }
    printf("So cap so trong day so co tong bang x la %d\n\n",dem);

    int demsnt = 0;
    for(i = 0; i < n; i++){
        int xet = 0;
        if(arr[i] > 10){
            for(int j = 2; j <= sqrt(arr[i]); j++){
                if(arr[i] % j == 0){
                    xet++;
                    break;
                }
            }
            if(xet == 0){
                demsnt++;   
            }
        }
    }
    (demsnt != 0) ? printf("So phan tu la so nguyen to lon hon 10 la %d\n\n",demsnt) :  printf("Khong co so nguyen to nao trong day so lon hon 10\n\n");

    int xet = arr[1]/arr[0];
    dem=0;
    for(i = 2 ;i < n; i++){
        if(arr[i]/arr[i-1]==xet){
            dem++;
        }
    }
    (dem==(n-2)) ? printf("Day so la cap so nhan\n\n") : printf("Day so khong phai la cap so nhan\n\n");

    dem = 0;
    for(i = 0; i < n; i++){
        int tong = 1;
        for(int j = 2;j <= sqrt(arr[i]); j++){
            if(arr[i] % j == 0){
                tong += j;
                if(j != arr[i]/j){
                    tong += arr[i]/j;
                }
            }
        }
        if(tong == arr[i]){
            dem++;
        }
    }(dem != 0) ? printf("Day so co %d so hoan hao", dem) : printf("Day so khong có so hoan hao");
    
    return 0;    
}