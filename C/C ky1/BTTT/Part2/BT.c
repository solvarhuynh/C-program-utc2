#include <stdio.h>

int main(){
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d",&n);

    if(n>100){
        return printf("Vui long nhap lai so phan tu nho hon hoac bang 100");
    }
    else{
        int arr[n];
        for (int i = 0; i<n;i++){
        printf("Nhap phan tu thu %d vao mang: ",i+1);
        scanf("%d",&arr[i]);
        }
        
        printf("Cac phan tu trong mang la: ");
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }printf("\n");

        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        printf("Day so co trung binh cong = %.2f\n",sum/(n*1.0));

        int max = arr[0];
        for(int i=1;i<n;i++){
            if (arr[i]>max){
                max = arr[i];
            }
        }
        printf("So lon nhat trong mang la: %d\n",max);

        int count =  0;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                count ++;
            }
        }
        if(count!=0){
            printf("So phan tu am trong mang la: %d\n", count);
        }else{
            printf("Day so khong co phan tu am\n");
        }
        
        
        for (int i = 1;i<n;i++){
            for (int j = 0;j<i;j++){
                if (arr[i]<arr[j]){
                    int tmp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=tmp;
                }
            }
        }
        printf("So nho thu hai trong mang la: %d\n", arr[1]);

        int d = arr[1]-arr[0];
        int giatrixet = 1;
        for (int i = 1;i<n;i++){
            if((arr[i]-arr[i-1]) != d){
                giatrixet = 0;
                break;
            }
        }
        if(giatrixet == 1){
            printf("Day so la mot cap so cong\n");
        }else{
            printf("Day so khong phai la mot cap so cong\n");
        }

        int x,xet=0;
        printf("Nhap gia tri x can xet: ");
        scanf("%d",&x);
        for (int i = 0;i<n;i++){
            if(arr[i]==x){
                printf("Day so co phan tu thu %d bang %d\n",i+1,x);
                xet = 1;
            }
        }
        if(xet == 0){
            printf("Day so khong co phan tu nao bang %d\n",x);
        }
    }

    return 0;
}