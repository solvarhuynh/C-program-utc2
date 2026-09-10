#include <stdio.h>
#include <math.h>
float cong(float a, float b){
    return a + b;
}
float tru(float a, float b){
    return a - b;
}
float nhan(float a, float b){
    return a * b;
}
float chia(float a, float b){
    return a / b;
}
float cbtn(float a, float n){
    return pow(a,n);
}
float ptb1(float a, float b){
    if(a == 0){
        if(b == 0){
            return printf("Phuong trinh vo so nghiem\n");
        }else{
            return printf("Phuong trinh vo nghiem\n");
        }
    }else{
        return -b/a;
    }
}
float ptb2(float a, float b, float delta){
    if(a == 0){
        return ptb1;
    }else{
        delta = pow(b,2)
    }
}