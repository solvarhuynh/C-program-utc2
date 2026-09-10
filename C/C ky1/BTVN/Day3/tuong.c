// #include <stdio.h>
// #include <math.h>
// void SNT(int n){
//     int x = 2, count = 0;
//     while(count < n){
//         int test = 1;
//         for(int i=2; i<= sqrt(x); i++){
//             if(x%i==0){
//                 test = 0;
//                 break;
//             }
//         }
//         if(test != 0){
//             printf("%d ", x);
//             count ++;
//         }
//         x++;
//     }
// }
// int main(){
//     int n;
//     do{
//         printf("Enter n Prime number: ");
//         scanf("%d",&n);
//     }while(n<=0);

//     SNT(n);
// }
#include <stdio.h>
#include <math.h>

int checkSNT(int n){
    if(n<2) return 0;
    for(int i=2; i<sqrt(n); i++){
        if(n%2==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    int i = 2, count = 0;
    printf("Enter n Prime number: ");
    scanf("%d",&n);
    
    while(count<n){
        if(checkSNT(i) == 1){
            count ++;
            printf("%d ",i);
        }
        i++;
    }

}

