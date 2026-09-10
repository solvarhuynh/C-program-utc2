#include <stdio.h>
#include <math.h>

//nhap n phan tu
void inputN(int *N){
    do{
        printf("Enter N: ");
        scanf("%d", N);
    }while(*N<=2 || *N >= 1000);
}

// kiem tra 1 so co phai la so Nguyen to hay khong
int checkPrimeNumber(int n){
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

// tim cac so nguyen to nho hon N
void findPrimeNumber(int N, int array[], int *count){
    printf("The Prime Numbers less than N are: ");
    for(int i = 2; i<N;i++){
        if(checkPrimeNumber(i) == 1){
            array[(*count)++] = i;
            printf("%d ", i);
        }
    }
}

//tim cap so nguyen to co tong bang N
void pairOfNumbers(int array[], int N,int count){
    int found = 0;
    for(int i  = 0; i<count-1; i++){
        for(int j = i+1; j<count; j++){
            if(array[i]+array[j] == N){ 
                if(found == 0)
                    printf("\nThe pairs of numbers whose sum is N are:");             
                printf("\n(%d,%d) = %d",array[i],array[j],N);
                found = 1;
            }
        }
    }
    if(!found){
        printf("\nThere is no pair of numbers whose sum is N.\n");
    }
}

int main(){
    //khai bao N
    int N;
    //Nhap N
    inputN(&N);
    //khai bao mang va bien dem
    int array[100], count = 0;
    //tim cac so nguyen to nho hon N
    findPrimeNumber(N,array,&count);
    //tim cap so nguyen to co tong bang N
    pairOfNumbers(array,N,count);

}
