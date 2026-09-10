#include <stdio.h>
#include <math.h>

int prime(int n){
    if(n<2) return 0;
    else{
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i==0)
                return 0;
        }
    }
    return 1;
}

int main(){
    
    int count = 0;
    FILE *f;
    f = fopen("D:/ML/C/C K2/TH/prime.txt","a");
    for(int i = 1; i<= 200; i++){
        if(prime(i)){
            fprintf(f,"%d ",i);
            count ++;
            if(count % 10 == 0)
                fprintf(f,"\n");
        }
    }
    fclose(f);
    return 0;
}