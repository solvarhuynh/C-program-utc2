#include <stdio.h>
int main(){
    float d, r;
    printf("Enter the rectangle's lenght: ");
    scanf("%f",&d);
    printf("Enter the rectangle's wight: ");
    scanf("%f",&r);

    (d <= 0 || r <= 0) ?  printf("Can't calculate") : printf("The area is: %.2f",d*r);
}