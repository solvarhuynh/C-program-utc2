#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct diem{
    float x,y;
}diem;

void input(diem *toaDo, int n){
    for(int i =0; i<n; i++){
        printf("Nhap toa do (x%d;y%d): ",i+1,i+1);
        scanf("%f%f",&(toaDo + i)->x,&(toaDo+i)->y);
    }

}

float doDai(diem *toaDo, int n){
    float result,dx,dy;
    for(int i = 0; i < n; i++){
        dx = (toaDo+i+1)->x - (toaDo+i)->x; //(toaDo+i+1)->x <=> *(toaDo+i+1).x
        dy = (toaDo+i+1)->y - (toaDo+i)->y;
        result += sqrt(dx * dx + dy * dy);
    }
    return result;
}

void diemOx(diem *toaDo, int n){
    float toaDoY = fabs(toaDo->y);
    for(int i = 1; i<n; i++){
        if(toaDoY < fabs((toaDo+i)->y))
            toaDoY = fabs((toaDo+i)->y);
    }
    printf("\nDiem xa truc hoanh nhat la: ");
    for(int i = 0; i<n; i++){
        if(toaDoY == fabs((toaDo+i)->y)){
            printf("(%.1f;%.1f)\t",(toaDo+i)->x, (toaDo+i)->y);
        }
    }
}

void diemCatOy(diem *toaDo, int n) {
    int count = 0;
    for(int i = 0; i < n-1; i++){
        if (((toaDo+i)->x<0 && (toaDo+i+1)->x>0) || ((toaDo+i)->x>0 && (toaDo+i+1)->x<0))
            count++;
    }
    printf("\n\nSo doan cat truc tung la: %d\n",count);

    printf("Cac doan cat truc tung:\n");
    for(int i = 0; i<n-1; i++){
        if (((toaDo+i)->x<0 && (toaDo+i+1)->x>0) || ((toaDo+i)->x>0 && (toaDo+i+1)->x<0))
            printf("\tDoan thang tu (%.1f,%.1f) to (%.1f,%.1f)\n",(toaDo+i)->x,(toaDo+i)->y,(toaDo+i+1)->x,(toaDo+i+1)->y);
    }
}


int main(){
    int n;
    printf("Nhap so toa do: ");
    scanf("%d", &n);
    diem *toaDo = (diem *)malloc(n*sizeof(diem));
    input(toaDo,n);
    printf("\nDo dai duong gap khuc: %.2f\n",doDai(toaDo,n));
    diemOx(toaDo, n);
    diemCatOy(toaDo,n);
}