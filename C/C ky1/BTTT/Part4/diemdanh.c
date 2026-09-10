// day so
// nhap vao 1 day so nguyen, xuat ra man hinh
// Tinh tong day so
// Viet ham: tong cac so duong, tinh trung binh cong, 
// tim so lon nhat.
#include<stdio.h>
// Tham so hinh thuc: 
void Nhap(int mang[], int sopt); 
void Xuat(int mang[], int sopt);
void Tong(int mang[], int sopt); 
void tongsoduong(int mang[], int n){
	int sum = 0;
	for(int i = 0; i < n; i++){
		if(mang[i]>0){
			sum += mang[i];
		}
	}
	(sum != 0) ? printf("Tong cac so duong trong mang la %.d\n",sum) : printf("Day so khong co so duong\n");
}
float tbc(int mang[], int n){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += mang[i];
	}
	return printf("Trung binh cong cua day so la %.2f\n",sum/(1.0*n));
}
int somax(int mang[], int n){
	int max = mang[0];
	for(int i = 1; i < n; i++){
		if(max < mang[i]){
			max = mang[i];
		}
	}
	return printf("So lon nhat trong mang la: %d\n", max);
}
int main(){
	int n, a[100], tong;
	int m, b[100], tong1;
	printf("Nhap n: ");
	scanf("%d",&n);
	Nhap(a,n);
	Xuat(a,n);
	Tong(a,n);
	
	printf("Nhap m: ");
	scanf("%d",&m);
	Nhap(b,m);
	Xuat(b,m);
	Tong(b,m);
	tongsoduong(a,n);
	tongsoduong(b,m);
	tbc(a,n);
	tbc(b,m);
	somax(a,n);
	somax(b,m);
}
void Nhap(int mang[], int sopt){
	for(int i=0;i<sopt;i++){
		printf("Nhap phan tu thu %d = ", i);
		scanf("%d",&mang[i]);
	}
}
void Xuat(int mang[], int sopt){
	printf("Mang da nhap vao la: ");
	for(int i=0;i<sopt;i++){
		printf("%d ",mang[i]);
	}
}
void Tong(int mang[], int sopt){
	int t=0;
	for(int i=0;i<sopt;i++){
		t=t+mang[i];
	}
	printf("\nTong day la: %d\n", t);
}


