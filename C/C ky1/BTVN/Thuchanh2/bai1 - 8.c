#include <stdio.h>
#include <math.h>
void input(int array[], int n){
    for(int i=0; i<n; i++){
        printf("Enter a[%d]: ",i+1);
        scanf("%d",&array[i]);
    }
}
//B1
float average(int array[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += array[i];
    }
    return sum/(1.0*n);
}
//B2
void output(int array[], int n){
    for(int i=0; i<n; i++){
        printf("%d%s",array[i],((i+1) % 10 == 0) ? "\n" : " ");
    }
}
//B3
void ascending(int array[], int n){
    int arrAsc[n];
    for(int i=0; i<n; i++){
        arrAsc[i] = array[i];
    }
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if(arrAsc[j] < arrAsc[i]){
                int tmp = arrAsc[i];
                arrAsc[i] = arrAsc[j];
                arrAsc[j] = tmp; 
            }
        }
    }
    printf("\nB3. The sequence arranged in ascending order is:\n");
    output(arrAsc,n);
}

void descending(int array[], int n){
    int arrDes[n];
    for(int i=0; i<n; i++){
        arrDes[i] = array[i];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arrDes[j] < arrDes[i]){
                int tmp = arrDes[i];
                arrDes[i] = arrDes[j];
                arrDes[j] = tmp; 
            }
        }
    }
    printf("\nB4. The sequence arranged in descending order is:\n");
    for(int i = 0; i<n; i++){
        printf("%d ",arrDes[i]);
    }
}
//B5
int countNegativeNumber(int array[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(array[i]<0){
            count++;
        }
    }
    return count;
}
//B6
int countPositiveNumber(int array[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(array[i]>0){
            count++;
        }
    }
    return count;
}
//B7
int checkPrimeNumber(int n){
    if(n<2) return 0;
    for(int j=2; j<=sqrt(n); j++){
        if(n%j == 0){
            return 0;
        }
    }
    return 1;
}
//B8
int max(int array[], int n){
    int sln = array[0];
    for(int i=0; i<n; i++){
        if(sln < array[i]){
            sln = array[i];
        }
    }
    return sln;
}

int main(){
    int n;
    printf("Enter n elements: ");
    scanf("%d",&n);
    int array[n];
    input(array,n);
    
    printf("B1. The average of the sequence is: %.2f\n",average(array,n));

    printf("B2. The elements of the sequence are:\n");
    output(array,n); //B2

    ascending(array,n);     //B3

    descending(array,n);     //B4

    printf("\nB5. The sequence has %d negative number\n", countNegativeNumber(array,n));

    printf("B6. The sequence has %d positive number\n", countPositiveNumber(array,n));

    int count = 0;
    for(int i=0; i<n; i++){
        if(checkPrimeNumber(array[i])==1){
            count++;
        }
    }
    if(count!=0)
        printf("B7. The sequence has %d prime number\n",count);
    else
        printf("B7. The sequence has no prime number\n");

    printf("B8. The largest number in the sequence is: %d\n",max(array,n));
}