#include <stdio.h>
void input(int a[], int n){
    for(int i=0; i<n; i++){
        printf("Enter a[%d]: ",i+1);
        scanf("%d",&a[i]);            
    }
}
int sum(int a[], int n){
    int s = 0;
    for(int i=0; i<n; i++){
        s += a[i];
    }
    return s;
}

int main(){
    int n;
    printf("Enter n integers: ");
    scanf("%d",&n);

    int a[n];
    input(a,n);
    printf("B9. The sum of elements in the sequence is: %d",sum(a,n));
}