#include <stdio.h>
int ucln(int a, int b);
int main(){
    int a,b;
    printf("Nhap a,b: ");
    scanf("%d%d",&a,&b);
    printf("UCLN cua %d va %d la: %d\n",a,b,ucln(a,b));
}
int ucln(int a, int b){
    if(a == 0 || b == 0) return a+b;
    else
        while(a != b){
            if(a>b) a=a-b;
            else b=b-a;
        }return a;
}

