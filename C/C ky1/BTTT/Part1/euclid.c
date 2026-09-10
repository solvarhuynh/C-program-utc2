#include <stdio.h>
#include <math.h>
int UCLN(int a,int b){
    if(b==0){
        return a;
    }else{
        return UCLN(b,a%b);
    }
}
int main(){
    int a, b;
    printf("Nhap 2 so can tinh UCLN: ");
    scanf("%d%d",&a,&b);
    printf("UCLN cua 2 so %d va %d la: %d",a,b,UCLN(a,b));
}