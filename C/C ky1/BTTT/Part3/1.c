#include <stdio.h>
int tong(int n){
    if(n==1){
        return 2;
    }else{
        return n*2 + tong()
    }
}