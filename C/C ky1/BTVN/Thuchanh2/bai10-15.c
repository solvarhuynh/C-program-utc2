#include <stdio.h>
#include <math.h>

void input(int a[], int n){
    for(int i=0; i<n; i++){
        do{
            printf("Enter a[%d]: ",i+1);
            scanf("%d",&a[i]); 
        }while(a[i]<=0);
    }
}
//B10
int evensum(int a[], int n){
    int s = 0;
    for(int i=0; i<n; i++){
        if(a[i] % 2 == 0){
            s += a[i];
        }
    }return s;

}
//B11
int oddsum(int a[], int n){
    int s = 0;
    for(int i=0; i<n; i++){
        if(a[i] % 2 != 0){
            s += a[i];
        }
    }return s;
}

//B12
int count52(int a[], int n, int x, int y){
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i]%5 == 2 && a[i] >= x && a[i] <= y){
           count ++; 
        } 
    }
    return count;
}
//B13
float evenTBC(int a[], int n){
    int s=0, x=0;
    for(int i=0; i<n; i++){
        if(a[i] % 2 == 0){
            s += a[i];
            x++;
        }
    }
    return s/(1.0*x);
}
//B14
float evenTBN(int a[], int n){
    int s=0, x=0;
    for(int i=0; i<n; i++){
        if(a[i] % 2 == 0){
            s += a[i];
            x++;
        }
    }
    return pow(s,1.0/x);
}
//B15
int count37(int a[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i]%3 == 0 && a[i]%7 == 0 && a[i] >= 1 && a[i] <= 100) count ++;
    }
    return count;
}

int main(){
    int n;
    do{
        printf("Enter n positive integers: ");
        scanf("%d",&n);
    }while(n<=0);

    int a[n];
    input(a,n);

    printf("B10. The sum of the even-value elements is: %d\n", evensum(a,n));    //B10

    printf("B11. The sum of the odd-value elements is: %d\n", oddsum(a,n));    //B11

    int x,y,test;
    printf("Enter [x ; y]: ");
    scanf("%d%d",&x,&y);
    test = count52(a,n,x,y);
    if(test == 0){
        printf("B.12 The sequence hasn't elements that, when divided by 5, remainder 2 in the range [%d,%d]",x,y);
    }else{
        printf("B.12 The number of elements that, when divided by 5, remainder 2 in the range [%d,%d] is: %d\n",x,y,test); //B12
    }

    printf("B.13 The average of even-number in the sequence is: %.2f\n", evenTBC(a,n)); //B13

    printf("B.14 The geometric mean of even-number in the sequence is: %.2f\n", evenTBN(a,n)); //B14

    printf("B.15 The number of elements divisible by 3 and 7 in the range [1;100] is: %d",count37(a,n)); //B15
}