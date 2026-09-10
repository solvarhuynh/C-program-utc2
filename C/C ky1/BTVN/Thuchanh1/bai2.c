#include <stdio.h>
#include <math.h>
int main(){
    float a, b, c;
    printf("Enter a: ");
    scanf("%f",&a);
    printf("Enter b: ");
    scanf("%f",&b);
    printf("Enter c: ");
    scanf("%f",&c);

    if (a<b+c && b<a+c && c<a+b){
        float p = (a + b + c)/2;
        printf("The triangle's area is: %.2f\n",sqrt(p*(p-a)*(p-b)*(p-c)));
        printf("The triangle's perimeter is: %.2f",a+b+c);
    }else{
        printf("Three sides don't form a triangle");
    }
}