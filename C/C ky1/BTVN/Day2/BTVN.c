#include <stdio.h>
#include <math.h>
int main(){
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d",&n);
    
    if(n<=0){
        return printf("Vui long nhap so phan tu lon hon 0");
    }

    int arr[n],i=0;
    while (i<n){
        printf("Nhap gia tri cua phan tu thu %d: ",i+1);
        scanf("%d",&arr[i]);
        i++;
    }
    
    printf("Cac phan tu co trong mang la:\n");
    for(i=0;i<n;i++){
        printf("%d%s",arr[i],((i+1)%10 == 0 ? "\n":" "));
    }printf("\n");
    
    int max = arr[0],min = arr[0];
    for (i=1;i<n;i++){
        if(max < arr[i]){
            max = arr[i];
        }
        if(min > arr[i]){
            min = arr[i];
        }
    }
    printf("Mang co max = %d va co min = %d\n",max,min);

    int min_duong = -1;
    for (i=0;i<n;i++){
        if(arr[i]>0){
            min_duong = arr[i];
            for(i+1;i<n;i++){
                if(min_duong > arr[i+1] && arr[i+1]>0){
                    min_duong = arr[i+1];
                }
            }
            break;
        }
    }(min_duong == -1) ? printf("Day so khong co so duong\n") : printf("Gia tri duong nho nhat cua mang = %d\n",min_duong);
    
    int sum = 0,tich = 1;
    for(i=0;i<n;i++){
        sum+=arr[i];
        tich*=arr[i];
    }
    printf("Tong cua day so = %d\nTrung binh cong cua day so = %.1f\n",sum,sum/(n*1.0));

    if(tich < 0 && n%2 == 0){
        printf("Khong ton tai trung binh nhan cua day so\n");
    }else if(tich < 0 && n%2!=0){
        tich =-tich;
        printf("Trung binh nhan cua day so = %.2lf\n",-pow(tich,1.0/n));
    }else{
        printf("Trung binh nhan cua day so = %.2lf\n",pow(tich,1.0/n));
    }

    int x,dem=0;
    printf("Nhap phan tu x can xet co trong mang khong: ");
    scanf("%d",&x);
    for(i=0;i<n;i++){
        if(arr[i]==x){
            printf("So %d la phan tu thu %d cua mang\n",x,i+1);
            dem = 1;
        }
    }(dem == 0) ? printf("Khong co phan tu nao trong mang = %d\n",x):printf("");
    
    int tang_dan[n],giam_dan[n];
    for(i=0;i<n;i++){
        tang_dan[i] = arr[i];
        giam_dan[i] = arr[i];
    }
    
    for(i=1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(tang_dan[i]<tang_dan[j]){
                int tmp1 = tang_dan[i];
                tang_dan[i] = tang_dan[j];
                tang_dan[j] = tmp1;
            }
        }
    }
    int h = n-1,l=0;
    while (h>=0){
        giam_dan[l]=tang_dan[h];
        h--;
        l++;
    }
    
    printf("Day so sep theo thu tu tang dan la: ");
    for(i=0;i<n;i++){
        printf("%d ",tang_dan[i]);
    }printf("\n");

    printf("Day so sep theo thu tu giam dan la: ");
    for(i=0;i<n;i++){
        printf("%d ",giam_dan[i]);
    }printf("\n");

    int mang_dao_nguoc[n],j=0;
    for(i = 0;i<n;i--){
        mang_dao_nguoc[i]=arr[n-1-i];
    }
    printf("Day dao nguoc la: ");
    for(i=0;i<n;i++){
        printf("%d ",mang_dao_nguoc[i]);
    }printf("\n");

    int arr_them[n+1],k;
    printf("Nhap phan tu x can them vao mang: ");
    scanf("%d",&x);
    do{
        printf("Nhap vi tri k cua phan tu can them: ");
        scanf("%d",&k);
    }while(k <= 0 || k > n);
    
    for (i=0;i<k;i++){
        arr_them[i]=arr[i];
    }
    arr_them[k-1]=x;
    for(i=k;i<n+1;i++){
        arr_them[i]=arr[i-1];
    }
    printf("Day so sau khi them x = %d vao vi tri thu k = %d la: ",x,k);
    for (i = 0;i<n+1;i++){
        printf("%d ",arr_them[i]);
    }
    printf("\n");
     
    do{
        printf("Nhap vi tri k can xoa khoi day so: ");
        scanf("%d",&k);
    }while(k <= 0 || k > n);

    int arr_xoa[n-1];
    for (i=0;i<k;i++){
        arr_xoa[i]=arr[i];
    }
    for (i=0;i<n;i++){
        if(arr_xoa[i]==arr[k]){
            continue;
        }
    }
    printf("Day so khi xoa di vi tri thu %d la: ",k);
    for(i=0;i<n-1;i++){
        printf("%d ",arr_xoa[i]);
    }
    printf("\n");

    int tong = 0, count = 0;
    for(i=0;i<n;i++){
        if(arr[i]>0){
            tong += arr[i];
            count++;
        }
    }
    printf("So phan tu duong trong mang: %d\nTong cac phan tu duong = %d\n",count,tong);
    
    int xet=0;
    for(i=0;i<n/2;i++){
        if(arr[i]==arr[n-1-i]){
            xet++;
        }else{
            break;
        }
    }
    if(xet == n/2){
        printf("Day so nay doi xung\n");
    }else{
        printf("Day so khong doi xung\n");
    }

    xet = 0;
    for(i=0;i<n-1;i++){
        if(arr[i]<=arr[i+1]){
            xet++;
        }else{
            break;
        }
    }
    if(xet == n-1){
        printf("Day so duoc sep theo thu tu tang dan\n");
    }else{
        printf("Day so khong duoc sep theo thu tu tang dan\n");
    }

    dem = 0;
    for(i=0;i<n;i++){
        for(j=2;j<=arr[i];j++){
            if(arr[i]%j==0){
                if(arr[i]==j){
                    dem++;
                }else{
                    break;
                }
            }
        } 
    }
    (dem!=0) ? printf("So phan tu la so nguyen to la: %d\n",dem) : printf("Day so khong co so nguyen to\n");

    dem=0;
    for (i = 0;i<n-2;i++){
        if(arr[i+2]==(arr[i+1]+arr[i])){
            dem++;
        }
    }
    if(dem!=0){
        printf("Day so co %d cap so, ma so sau bang tong 2 so truoc\n",dem);
    }else{
        printf("Day so khong co cap so nao ma so sau bang tong 2 so truoc\n");
    }
    
    int tmp = 0;
    dem = 0;
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            tmp = arr[i]+arr[j];
            for(int y = 2;y<=tmp;y++){
                if(tmp%y==0){
                    if(tmp==y && i != j){
                        dem++; 
                    }else{
                        break;
                    }
                }
            }
        }
    }
    (dem!=0) ? printf("So cap arr[i] + arr[j] la so nguyen to la: %d\n",dem) : printf("Khong co cap arr[i] + arr[j] nao la so nguyen to");

    return 0;
}