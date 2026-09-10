//Huỳnh Trung Nghĩa - MSSV: 6551071057

// Nhập vào mảng 1 chiều gồm n phần tử (n phải là số dương <=100 phần tử)
// Thực hiện trên dãy số các yêu cầu sau:
// 1.	Đếm xem dãy số có bao nhiêu số nguyên tố lớn hơn 10 và xuất các số đó ra màn hình
// 2.	Kiểm tra xem dãy số tăng dần hay không?
// 3.	Dãy số có tạo thành cấp số nhân
// 4.	Tìm số dương nhỏ nhất
// 5.	Tính trung bình cộng các phần tử ở vị trí chẵn 2 4 6
// 6.	Tìm các số chẵn có 3 ước
// 7.	Tìm giá trị xuất hiện nhiều lần nhất trong dãy số
// 8.	Xóa các phần tử có giá trị âm trong dãy số
// 9.	Liệt kê tần suất xuất hiện các giá trị
// 10.	Hiển thị các số tổng các ước là số nguyên tố

#include <stdio.h>
#include <math.h>

void nhap(int arr[], int n);
void xuat(int arr[], int n);
int ktSoNguyenTo10(int arr[], int n, int arrtmp[]);
void tangDan(int arr[], int n);
void ktCapSoNhan(int arr[], int n);
int soDuongNhoNhat(int arr[], int n);
float tbcViTriChan(int arr[], int n);
void soChan3Uoc(int arr[], int n); 
void tanSoXuatHien(int arr[], int n,int dk, int *maxTS,int giatri[],int *bienchay);
void xoaGiaTriAm(int arr[], int n);
void tongUoclaSNT(int arr[], int n);

// Thoi gian hoan thanh thu thach la luc 2 tieng 57p (trong do code xong khoang 1 tieng ruoi va fix bug cung gan 1 tieng ruoi)

int main(){
    int arr[100], n;
    do{
        printf("Nhap so phan tu: ");
        scanf("%d",&n);
    }while(n<=0 || n > 100);

    nhap(arr,n);

    int arrtmp[100];
    int dem = ktSoNguyenTo10(arr,n,arrtmp);
    if(dem == 0){
        printf("Day so khong co so nguyen to nao lon hon 10\n");
    }else{
        printf("Day so co %d so nguyen to lon hon 10 la: \n", dem);
        xuat(arrtmp,dem);
        printf("\n");
    }

    tangDan(arr,n);
    ktCapSoNhan(arr, n);

    if(soDuongNhoNhat(arr,n) != -1){
        printf("Day so co so duong nho nhat la: %d\n", soDuongNhoNhat(arr,n));
    }else{
        printf("Day so khong co so duong\n");
    }

    if(n == 1){
        printf("Day so khong co vi tri chan\n");
    }else{
        printf("Day so co TBC cac so o vi tri chan la: %.2f\n",tbcViTriChan(arr,n));
    }

    soChan3Uoc(arr,n);

    int dk = 0, maxTS = 0, giatri[100], bienchay = 0;
    tanSoXuatHien(arr,n,dk,&maxTS,giatri,&bienchay);
    if(bienchay == 0){
        printf("Phan tu %d co so lan xuat hien nhieu nhat la: %d\n",giatri[0],maxTS);
    }else{
        printf("Cac phan tu co %d lan xuat hien la nhieu nhat la:\n", maxTS);
        xuat(giatri,bienchay+1);
        printf("\n");
    }
    xoaGiaTriAm(arr,n);

    tanSoXuatHien(arr,n,dk+1,&maxTS,giatri,&bienchay);

    tongUoclaSNT(arr,n);
}

void nhap(int arr[], int n){
    for(int i  = 0; i<n; i++){
        printf("Nhap phan tu thu %d vao mang: ",i+1);
        scanf("%d",&arr[i]);
    }
}
void xuat(int arr[], int n){
    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
}

int ktSoNguyenTo10(int arr[], int n, int arrtmp[]){
    int dem = 0;
    for(int i = 0; i<n; i++){
        int xet = 1;
        if(arr[i] < 2){
            xet = 0;
        }else{
            for(int j = 2; j<sqrt(arr[i]); j++){
                if(arr[i]%j==0){
                    xet = 0;
                    break;
                }
            }
        }
        if(xet == 1 && arr[i] > 10){
            arrtmp[dem] = arr[i];
            dem++;
        }
    }
    return dem;
}

void tangDan(int arr[], int n){
    int dem = 0;
    for(int i = 0; i<n-1; i++){
        if(arr[i]<arr[i+1])
            dem++;
    }
    if(dem == n - 1){
        printf("Day so la day tang dan\n");
    }else{
        printf("Day so khong phai la day tang dan\n");
    }
}

void ktCapSoNhan(int arr[], int n){
    float kt = arr[1]/arr[0];
    int xet = 0;
    for(int i = 1; i<n; i++){
        if(arr[i+1]/arr[i] == kt){
            xet ++;
        }
    }
    if(xet == n - 2){
        printf("Day so la mot cap so nhan\n");
    }else{
        printf("Day so khong phai la mot cap so nhan\n");
    }
}

int soDuongNhoNhat(int arr[], int n){
    int min = -1;
    for(int i = 0; i<n; i++){
        if(arr[i] > 0)
            min = arr[i];
            break;
    }
    for(int i = 0; i<n; i++){
        if(min > arr[i] && arr[i]>0){
            min = arr[i];
        }
    }
    return min;
}

float tbcViTriChan(int arr[], int n){
    int sum = 0, dem = 0;
    for(int i = 1; i<n; i += 2){
        sum += arr[i];
        dem++;
    }
    return sum/(1.0*dem);
}

void soChan3Uoc(int arr[], int n){
    int xetSoUoc = 0, dem = 0, uoc[100];

    for(int i = 0; i<n; i++){
        if(arr[i]%2 == 0){
            for(int j = 1; j<sqrt(arr[i]); j++){
                if(arr[i]%j == 0){
                    xetSoUoc++;
                    if(j != arr[i]/j)
                        xetSoUoc++;
                }
            }
            if(xetSoUoc == 3){
                uoc[dem] = arr[i];
                dem++;
            }
        }
    }
    if(dem == 0){
        printf("Day so khong co so chan nao co 3 uoc\n");
    }else{
        printf("So chan co 3 uoc la:\n");
        xuat(uoc,dem);
        printf("\n");
    }
}

void tanSoXuatHien(int arr[], int n,int dk, int *maxTS, int giatri[],int *bienchay){
    int tmp[100] = {0}, demSoPT = 0;

    for(int i = 0; i<n; i++){
        if(tmp[i] == 0){
                int dem = 1;
            for(int j = i+1; j<n; j++){
                if(arr[i] == arr[j]){
                    dem++;
                    tmp[j] = 1;
                }
            }
            if(dk == 1){
                printf("Phan tu %d xuan hien %d lan\n",arr[i],dem);
            }else{
                if(*maxTS < dem){
                    *maxTS = dem;
                    *bienchay = 0;
                    giatri[*bienchay] = arr[i];
                }
                else if(*maxTS == dem){
                    (*bienchay) ++;
                    giatri[*bienchay] = arr[i];
                }
                
            }
        }
    }
}

void xoaGiaTriAm(int arr[], int n){
    int arrnew[100];

    for(int i = 0; i<n; i++){
        arrnew[i] = arr[i]; // em nghi vi con 1 cau 9 yeu cau so lan xh, neu xoa mang goc thi khong duoc;
    }

    int dem = 0;
    for(int i = 0; i<n; i++){
        if(arrnew[i] < 0 && i != n - 1){
            arrnew[i] = arrnew[i+1];
            dem++;
        }else if(arrnew[i] < 0 && i == n - 1){
            arrnew[i] = 0;
            dem++;
        }
    }
    if(dem != 0){
        printf("Day so da xoa gia tri am la:\n");
        xuat(arrnew,n-dem);
        printf("\n");
    }else{
        printf("Day so khong co gia tri am\n");
    }
}

int ktSoNguyenTo(int n){
    if(n<2){
        return 0;
    }else{
        for(int i = 2; i<sqrt(n); i++){
            if(n%i == 0)
                return 0;
        }
    }
    return 1;
}

void tongUoclaSNT(int arr[], int n){
    int dem = 0, arrSNT[100];

    for(int i = 0; i<n; i++){
        int tongUoc = 0;
        for(int j = 1; j<sqrt(arr[i]); j++){
            if(arr[i]%j == 0){
                tongUoc += j;
                if(j != arr[i]/j)
                    tongUoc += arr[i]/j;
            }
        }
        if(ktSoNguyenTo(tongUoc) == 1){
            arrSNT[dem] = arr[i];
            dem++;
        }
    }
    if(dem == 0){
        printf("Day so khong co so nao co tong uoc la so nguyen to\n");
    }else{
        printf("So co tong uoc la so nguyen to la:\n");
        xuat(arrSNT,dem);
    }
}

