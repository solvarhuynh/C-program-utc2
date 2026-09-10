#include<stdio.h>
#include<stdbool.h>

//nhap n la so nguyen duong nho hon hoac bang 100, sai nhap lai
void inputN(int *n){
    do{
        printf("Enter n: ");
        scanf("%d",n);
    }while(*n<0 || *n>100);
}

// nhap mang
void inputArray(int array[], int n){
    for(int i=0; i<n; i++){
        printf("Enter array[%d]: ",i);
        scanf("%d",&array[i]);
    }
} 

//xuat mang
void outputArray(int array[], int n){
    printf("\tArray\n");
    for(int i=0; i<n; i++){
        printf("array[%d]: %d\n", i,array[i]);
    }
}

//Thay doi gia tri moi V tai vi tri X trong array
void changeValueOfIndex(int array[], int n){
    //khai bao X va V
    int X,V;

    // nhap X va V
    do{
        printf("Enter X index: ");
        scanf("%d",&X);
    }while(X<0 || X>=n);
    
    printf("Enter V value array[%d] = ",X);
    scanf("%d",&V);

    // thay doi gia tri V tai vi tri X
    array[X] = V;
    outputArray(array, n);
}

void printMenu(){
    printf("\n==========Menu========\n");
    printf("1. Print Array.\n");
    printf("2. Chang Value of index. \n");
    printf("3. Exit.\n");
    printf("======================\n");
    printf("Enter Option: ");
}

void selectOption(int array[], int n){
    //khai bao option
    int option;
    bool condition = true;
    //in menu va nhap lua chon
    do{
        printMenu();
        scanf("%d",&option);

        switch(option){
        case 1:
            outputArray(array,n);
            break;
        case 2: 
            changeValueOfIndex(array,n);
            break;
        case 3:
            condition = false;
        default: condition = false;
    }
    }while(condition);
    
}

int main(){
    //khai bao so phan tu
    int n; 

    //nhap n la so nguyen duong nho hon hoac bang 100, sai nhap lai
    inputN(&n);

    //khai bao mang
    int array[n];

    // nhap mang
    inputArray(array,n);

    selectOption(array, n);

}
