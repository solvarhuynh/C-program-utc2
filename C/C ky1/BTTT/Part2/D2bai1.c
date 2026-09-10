#include<stdio.h>
int main(){
	int a[100], S;
	int n; // so phan tu
	printf("Nhap n: ");
	scanf("%d",&n);
	
	// nhap mang
	for(int i=0;i<n;i++){
		printf("Nhap a[%d] = ", i);
		scanf("%d",&a[i]);
	}
	//xuat mang
	printf("Mang da nhap vao la: \n");
	for(int i=0;i<n;i++){
		printf("a[%d] = %d\n",i,a[i]);
	}
	// Tinh tong day so
	S=0;
	for(int i=0;i<n;i++)
		S=S+a[i];
	printf("Tong day: %d\n", S);
	// Tong cac so le
    int sum =0;
    for(int i =0;i<n;i++){
        if(a[i]%2!=0){
            sum+=a[i];
        }
    }
    printf("Tong cac so le: %d",sum);
}
