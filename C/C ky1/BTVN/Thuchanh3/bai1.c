#include <stdio.h>
#include <math.h>

//nhap so phan tu
void inputN(int *n){
    do{
        printf("Enter n: ");
        scanf("%d",n);
    }while(n<0);
}

//Nhap vao mang
void inputArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("Enter arr[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }
}

//Xuat 1 dong 10 phan tu
void outputArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d%s",arr[i],((i+1) % 10 == 0) ? "\n" : " ");
    }
    printf("\n");
}

//tim max trong day so
int maxInArray(int arr[], int n){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(max < arr[i]) max = arr[i];
    }
    return max;
}

//tim min trong day so
int minInArray(int arr[], int n){
    int min = arr[0];
    for(int i=1; i<n; i++){
        if(min > arr[i]) min = arr[i];
    }
    return min;
}

//tim gia tri duong nho nhat
void findMinPos(int arr[], int n){
    int minPos = -1, index;
    for(int i = 0; i<n; i++){
        if(arr[i]>0){
            minPos = arr[i];
            index = i;
            break;
        }
    }
    for(int i = 0; i<n; i++){
        if(minPos > arr[i] && arr[i]>0){
            minPos = arr[i];
            index = i;
        }
    }
    if(minPos == -1)
        printf("\nThe sequence does not have any positive numbers.\n");
    else
        printf("\nThe minimum positive number is %d at index %d in the array.\n",minPos,index);
}

//tinh tong cua mang
int sumOfArray(int arr[], int n){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

//tinh trung binh cong cua mang
float averageOfArray(int arr[], int n){
    return sumOfArray(arr,n)/(1.0*n);
}

//tinh trung binh nhan cua mang
void geoMean(int arr[],int n){
    int multiply = 1;
    for(int i = 0; i<n; i++){
        multiply *= arr[i];
    }
    if(multiply < 0 && n%2 == 0)
        printf("\nGeometric mean does not exist.\n");
    else if(multiply < 0)
        printf("\nThe geometric mean of the sequence is: %.1f.\n", -pow(abs(multiply),1.0/n));
    else
        printf("\nThe geometric mean of the sequence is: %.1f.\n", pow(multiply,1.0/n));
}

//tim kiem phan tu x cho truoc
void findX(int arr[], int n, int x){
    int count = 0;
    for(int i = 0; i<n; i++){
        if(x == arr[i]){
            printf("\nThe value %d is at index %d in the array.\n",x,i);
            count = 1;
            break;
        }
    }
    if(count == 0){
        printf("\nThe value %d is not in the array.\n",x);
    } 
}

//sap xep mang theo thu tu tang dan
void arrayAsc(int arr[], int n){
    int arrAsc[n];
    for(int i = 0; i<n; i++){
        arrAsc[i] = arr[i];
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arrAsc[i] > arrAsc[j]){
                int tmp = arrAsc[i];
                arrAsc[i] = arrAsc[j];
                arrAsc[j] = tmp;
            }
        }
    }
    printf("\nThe sequence sorted in ascending order is:\n");
    outputArray(arrAsc,n);
}

//sap xep mang theo thu tu giam dan
void arrayDes(int arr[], int n){
    int arrDes[n];
    for(int i = 0; i<n; i++){
        arrDes[i] = arr[i];
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arrDes[i] < arrDes[j]){
                int tmp = arrDes[i];
                arrDes[i] = arrDes[j];
                arrDes[j] = tmp;
            }
        }
    }
    printf("\nThe sequence sorted in descending order is:\n");
    outputArray(arrDes,n);
}

//sap xem mang ban dau thanh mang dao nguoc
void reverseArray(int arr[], int n){
    printf("\nThe sequence sorted in reverse order is:\n");
    for(int i = n-1; i>=0; i--){
        printf("%d ", arr[i]);
    }
}

//them phan tu x vao vi tri k
void insertAt(int arr[], int n, int x, int k){
    // int arrInser[n+1];
    // for(int i = 0; i<k; i++){
    //     arrInser[i] = arr[i];
    // }
    // arrInser[k] = x;
    // for(int i = k+1; i<=n; i++){
    //     arrInser[i] = arr[i-1];
    // }
    printf("\nThe sequence sorted after inserting %d at index %d is:\n",x,k);
    for(int i = 0; i<k; i++){
        printf("%d ",arr[i]);
    }
    printf("%d ",x);
    for(int i = k; i<n; i++){
        printf("%d ", arr[i]);
    }
}

//xoa phan tu tai vi tri k
void removeAt(int arr[], int n, int k){
    // int arrRemove[n-1];
    // for(int i = 0; i<k; i++){
    //     arrRemove[i] = arr[i]
    // }
    // for(int i = k+1; i<n; i++){
    //     arrRemove[i-1] = arr[i];
    // }
    printf("\nThe sequence sorted after removing the element at index %d is:\n",k);
    for(int i = 0; i<n; i++){
        if(i == k){
            continue;
        }else{
            printf("%d ",arr[i]);
        }
    }
}

//dem so phan tu duong va in ra tong cua chung
void countAndSumPos(int arr[], int n){
    int count = 0, sum = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] > 0){
            count ++;
            sum += arr[i];
        }
    }
    printf("\nThe sum of %d positive elements is %d\n",count,sum);
}

//kiem tra mang co doi xung hay khong
void isSymmetric(int arr[], int n){
    int count = 0;
    for(int i = 0; i < n/2; i++){
        if(arr[i] == arr[n-1-i])
            count ++;
    }
    (count == n/2) ? printf("\nThis sequence is symmetric\n") : printf("\nThis sequence isn't symmetric\n");
}

//kiem tra mang co sap theo thu tu tang dan khong
void isAscending(int arr[], int n){
    int count = 0;
    for(int i = 1; i<n; i++){
        if(arr[i] > arr[i-1])
            count ++;
        else
            break;
    }
    (count == n-1) ? printf("\nThis sequence is ascending\n") : printf("\nThis sequence isn't ascending\n");
}

//kiem tra 1 so co phai la so nguyen to khong
int checkPrimeNumber(int n){
    if(n<2)
        return 0;
    else
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i == 0)
                return 0;
        }
    return 1;
}
//kiem tra mang co bao nhieu phan tu la so nguyen to
int countPrimes(int arr[], int n){
    int count = 0;
    for(int i = 0; i<n; i++){
        if(checkPrimeNumber(arr[i]) == 1){
            count ++;
        }
    }
    return count;
}

//kiem tra trong mang co bao nhieu cap so ma so sau bang tong 2 so truoc
void countFibonacciPairs(int arr[], int n){
    int count = 0;
    for(int i = 0; i<n-2; i++){
        if(arr[i+2] == arr[i] + arr[i+1]){
            count ++;
        }
    }
    if(count != 0)
        printf("\nThe sequence has %d pairs where the next number equals the sum of the two previous numbers.\n");
    else
        printf("\nThe sequence has no pairs where the next number equals the sum of the two previous numbers.\n");
}

//kiem tra mang co bao nhieu cap so ma co tong la 1 so nguyen to
void countPrimePairs(int arr[], int n){
    int count = 0;
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if(checkPrimeNumber(arr[i] + arr[j]) == 1)
                count ++;
        }
    }
    if(count != 0)
        printf("\nThe sequence has %d pairs with a prime sum.\n",count);
    else
        printf("\nThe sequence has no pairs whose sum is a prime number.\n");
}

//menu
void printMenu(){
    printf("\n+==================================== MENU ====================================+\n");
    printf("1. In mang ra theo quy tac 10 phan tu 1 hang.\n");
    printf("2. Tim min max trong mang.\n");
    printf("3. Tim gia tri duong nho nhat.\n");
    printf("4. Tinh tong cua mang.\n");
    printf("5. Tinh trung binh cong cua mang.\n");
    printf("6. Tinh trung binh nhan cua mang.\n");
    printf("7. Tim kiem phan tu x cho truoc.\n");
    printf("8. Sap xep mang theo thu tu tang dan.\n");
    printf("9. Sap xep mang theo thu tu giam dan.\n");
    printf("10. Sap xem mang ban dau thanh mang dao nguoc.\n");
    printf("11. Them phan tu x vao vi tri k.\n");
    printf("12. Xoa phan tu tai vi tri k.\n");
    printf("13. Dem so phan tu duong va in ra tong cua chung.\n");
    printf("14. Kiem tra mang co doi xung hay khong.\n");
    printf("15. Kiem tra mang co sap theo thu tu tang dan khong.\n");
    printf("16. Kiem tra mang co bao nhieu phan tu la so nguyen to.\n");
    printf("17. Kiem tra trong mang co bao nhieu cap so ma so sau bang tong 2 so truoc.\n");
    printf("18. Kiem tra mang co bao nhieu cap so ma co tong la 1 so nguyen to.\n");
    printf("19. Exit.\n");
    printf("+================================================================================+\n");
    printf("Please enter your choice: ");
}
//lua chon
void selectOption(int arr[], int n){
    int choice;
    do{
        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                //in mang ra theo quy tac 10 phan tu 1 hang
                printf("\nThe elements of the series are:\n");
                outputArray(arr,n);
                break;
            case 2:
                //tim min max trong mang
                printf("\nThe minimum value in the array is: %d\n",minInArray(arr,n));
                printf("The maximum value in the array is: %d\n",maxInArray(arr,n));
                break;
            case 3:
                //tim gia tri duong nho nhat
                findMinPos(arr,n);
                break;
            case 4:
                //tinh tong cua mang
                printf("\nThe sum of the sequence is: %d\n",sumOfArray(arr,n));
                break;
            case 5:
                //tinh trung binh cong cua mang
                printf("\nThe average of the sequence is: %.1f\n", averageOfArray(arr,n));
                break;
            case 6: 
                //tinh trung binh nhan cua mang
                geoMean(arr,n);
                break;
            case 7:
                //tim kiem phan tu x cho truoc
                int x;
                printf("\nEnter x: ");
                scanf("%d",&x);
                findX(arr,n,x);
                break;
            case 8:
                //sap xep mang theo thu tu tang dan
                arrayAsc(arr,n);
                break;
            case 9:
                //sap xep mang theo thu tu giam dan
                arrayDes(arr,n);
                break;
            case 10:
                //sap xem mang ban dau thanh mang dao nguoc
                reverseArray(arr,n);
                break;
            case 11:
                //them phan tu x vao vi tri k
                int k;
                printf("\nEnter x: ");
                scanf("%d",&x);
                do{
                    printf("Enter k: ");
                    scanf("%d",&k);
                }while(k<0 || k>=n);
                insertAt(arr,n,x,k);
                break;
            case 12:
                //xoa phan tu tai vi tri k
                do{
                    printf("\nEnter k: ");
                    scanf("%d",&k);
                }while(k<0 || k>=n);
                removeAt(arr,n,k);
                break;
            case 13:
                //dem so phan tu duong va in ra tong cua chung
                countAndSumPos(arr,n);
                break;
            case 14:
                //kiem tra mang co doi xung hay khong
                isSymmetric(arr,n);
                break;
            case 15:  
                //kiem tra mang co sap theo thu tu tang dan khong
                isAscending(arr,n);
                break;
            case 16:
                //kiem tra mang co bao nhieu phan tu la so nguyen to
                if(countPrimes(arr,n) == 0)
                    printf("\nThe sequence has no prime numbers\n");
                else   
                    printf("\nThe sequence has %d prime numbers\n", countPrimes(arr,n));
                break;
            case 17:
                //kiem tra trong mang co bao nhieu cap so ma so sau bang tong 2 so truoc
                countFibonacciPairs(arr,n);
                break;
            case 18:
                //kiem tra mang co bao nhieu cap so ma co tong la 1 so nguyen to
                countPrimePairs(arr,n);
                break;
            default: choice = 19;
        }
    }while(choice != 19);
}

int main(){
    //khai bao so phan tu n, khai bao mang
    int n, arr[100];

    //nhap so phan tu
    inputN(&n);

    //nhap phan tu vao mang
    inputArray(arr,n);
    
    //chon lua chon
    selectOption(arr, n);
}