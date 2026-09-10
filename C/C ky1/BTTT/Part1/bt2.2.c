#include <stdio.h>
int main(){
    int so_hoc_sinh;
    printf("so_hoc_sinh: ");
    scanf("%d",&so_hoc_sinh);
    float diem;
    for (int i = 0; i<so_hoc_sinh;i++){
        char ten[20];
        printf("Nhap ten hoc sinh: ");
        scanf(" %[^\n]",&ten);
        printf("Nhap diem tb: ");
        scanf("%f",&diem);
        if(diem>=8.5){
            printf("Hoc luc gioi\n");
        }else if(diem >=6.5){
            printf("Hoc luc kha\n");
        }else if(diem >=5){
            printf("Hoc luc trung binh\n");
        }else{
            printf("Hoc luc yeu\n");
        }
    }
    return 0;
}