#include <stdio.h>
#include <math.h>
#include <conio.h>

//lua chon dung phep toan
void math(float a, float b, char pt, float *result){
    switch(pt){
        case '+': *result = a+b; break;
        case '-': *result = a-b; break;
        case '*': *result = a*b; break;
        case '/': 
            if(b == 0){
                printf("\n====Error: Cannot divide by 0!");
                return;
            }
            else{
                *result = a/b; break;
            }
        case '^': *result = pow(a,b); break;
        default: printf("\n====Invalid operation!");
            return;
    }
}

//nhap 2 so a, b va phep toan
int main(){
    float a, b;
    char pt, op;
    do{
        float result = 0;
        //nhap cac gia tri
        printf("\nEnter a, b: ");
        scanf("%f%f",&a,&b);
        printf("Enter an operation: ");
        scanf(" %c",&pt);
        //tinh toan
        math(a,b,pt,&result);
        //in ra man hinh
        if(result){
            printf("\n%.1f %c %.1f = %.1f\n",a,pt,b,result);
        }else{
            printf(" plesae try agian later!\n");
        }
        printf("\nPress ESC or 'n' to exit, press any other key to continue: ");
        op = getch();
    }while(op != 'n' && op != 27);
}

