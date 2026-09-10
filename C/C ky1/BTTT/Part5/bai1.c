#include <stdio.h>
#include <math.h>
int main(){
    int n,sum=0;
    do{
        printf("Nhap so nguyen duong n: ");
        scanf("%d",&n);
    }while(n<=0);

    int i=1;
    while(i<=(2*n+1)){
        sum +=i; 
        i+=2;
    }
    printf("Tong S = 1 + 3 + 5 + ... + %d = %d\n\n",2*n+1,sum);

    do{
        printf("Nhap so nguyen duong n: ");
        scanf("%d",&n);
    }while(n<=0);

    long long giai_thua=1;i=1;
    while(i<=n){
        giai_thua *=i;
        i++;
    }
    printf("Giai thua cua %d = %ld\n\n",n,giai_thua);
    
    do{
        printf("Nhap so nguyen duong n: ");
        scanf("%d",&n);
    }while(n<=0);
    
    i=1;sum=0;
    while(i<=n){
        sum +=(i*(i+1)*(i+2)); 
        i++;
    }
    printf("Tong S = 1*2*3 + 2*3*4 + ... + %d*%d*%d = %d\n\n",n,n+1,n+2,sum);
    
    do{
        printf("Nhap so phan tu n: ");
        scanf("%d",&n);
    }while(n<=0);
    
    float x1,y1;
    int arr1[n],dem=0;
    for(i=0;i<n;i++){
        printf("Nhap phan tu thu %d vao mang: ",i+1);
        scanf("%d",&arr1[i]);
    }
    printf("Nhap doan [x,y]: ");
    scanf("%f%f",&x1,&y1);
    for(i=0;i<n;i++){
        if(arr1[i] % 5 == 2 && arr1[i] >= x1 && arr1[i] <= y1){
            dem++;
        }
    }
    (dem!=0) ? printf("So phan tu chia 5 du 2 thuoc doan [%.1f;%.1f] la %d\n\n",x1,y1,dem) : printf("Trong mang khong co so nao chia 5 du 2");
    
    do{
        printf("Nhap so phan tu n: ");
        scanf("%d",&n);
    }while(n<=0);
    
    int arr2[n];
    for(i=0;i<n;i++){
        printf("Nhap phan tu thu %d vao mang: ",i+1);
        scanf("%d",&arr2[i]);
    }
    
    sum=0;
    dem=0;
    for(i = 0;i<n;i++){
        if(arr2[i]%2==0){
            sum+=arr2[i];
            dem++;
        }
    }
    (dem!=0) ? printf("Trung binh cong cua cac so chan = %.2f\n\n",sum/(1.0*dem)) : printf("Trong day so khong co so chan");
    
    do{
        printf("Nhap so diem M: ");
        scanf("%d",&n);
    }while(n<=0);
    
    float x[n], y[n];
    for (i = 0;i<n;i++){
        printf("Nhap toa do diem M%d(x,y): ",i+1);
        scanf("%f%f",&x[i],&y[i]);
    }

    float do_dai = 0; 
    for(i=0;i<n-1;i++){
        do_dai += sqrt(pow(x[i+1]-x[i],2) + pow(y[i+1]-y[i],2));
    }
    printf("Do dai duong gap khuc di qua %d diem la: %.2f",n,do_dai);
    
    return 0;
}