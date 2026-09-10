//Huynh Trung Nghia va Bang
#include<stdio.h>
#include<math.h>

float cong(float a, float b){
	return a+b;	
}
float tru(float a, float b){
	return a-b;	
}
float nhan(float a, float b){
	return a*b;	
}
float chia(float a, float b){
	return a/b;	
}
float canBacN(int n, float x){
	float kq=pow(x,1.0/n);
	return kq;
}
void giaiPTBacNhat(float a, float b){
	if(a==0)
		if(b==0)
			printf("PTVSN");
		else
			printf("PTVN");
	else{
		float x=-b/a;
		printf("PT co nghiem: %.2f", x);
	}
}
void giaiPTBacHai(float a, float b, float c){
	if(a==0)
		giaiPTBacNhat(b,c);
	else{
		float d=b*b-4*a*c;
		if(d<0)
			printf("PTVSN");
		else if(d==0){
			float x=-b/(2*a);
			printf("PT co nghiem: %.2f", x);
		}
		else{
			float x1=(-b+sqrt(d))/(2*a);
			float x2=(-b-sqrt(d))/(2*a);
			printf("PT co 2 nghiem: %.2f, %.2f", x1, x2);
		}
	}
}
float triTuyetDoi(float a){
	if(a<0)
		return -a;
	else
		return a;
}
int main(){
	int choice;
	bool t= true;
	float a,b,c, x, n;
	while(t){
		printf("*******************************\n");
		printf("* 1. Cong                     *\n");
		printf("* 2. Tru                      *\n");
		printf("* 3. Nhan                     *\n");
		printf("* 4. Chia                     *\n");
		printf("* 5. Can bac thu n            *\n");
		printf("* 6. Giai PTBN                *\n");
		printf("* 7. Giai PTBH                *\n");
		printf("* 8. Tri tuyet doi            *\n");
		printf("* 9. Thoat                    *\n");
		printf("*******************************\n");
		printf("Moi ban lua chon: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap a, b: ");
				scanf("%f%f",&a,&b);			
				printf("Tong la: %.2f", cong(a,b));
				break;
			case 2: 
				printf("Nhap a, b: ");
				scanf("%f%f",&a,&b);
				printf("\nHieu la: %.2f", tru(a,b));
				break;
			case 3:
				printf("Nhap a, b: ");
				scanf("%f%f",&a,&b);
				printf("\nTich la: %.2f", nhan(a,b));
				break;
			case 4: 
				printf("Nhap a, b: ");
				scanf("%f%f",&a,&b);
				printf("\nThuong la: %.2f", chia(a,b));
				break;
			case 5: 
				printf("Nhap x, n: ");
				scanf("%f%f",&x,&n);
				printf("\nCan bac thu n cua x la %.2f", canBacN(n,x));
				break;
			case 6: 
				printf("Nhap a, b: ");
				scanf("%f%f",&a,&b);
				giaiPTBacNhat(a,b);
				break;
			case 7: 
				printf("Nhap a, b, c: ");
				scanf("%f%f%f",&a,&b,&c);
				giaiPTBacHai(a,b,c);
				break;
			case 8: 
				printf("Nhap a: ");
				scanf("%f",&a);
				printf("Tri tuyet doi cua a la %.2f", triTuyetDoi(a));
				break;
			case 9:
				t=false;
		}
	}
}

