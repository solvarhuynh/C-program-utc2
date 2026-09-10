#include <stdio.h>
#include <math.h>
float do_dai(float x1, float y1, float x2, float y2){
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}
int main(){
    float x1,x2,x3,y1,y2,y3;
    printf("Nhap toa do diem A: ");
    scanf("%f%f",&x1,&y1);
    printf("Nhap toa do diem B: ");
    scanf("%f%f",&x2,&y2);
    printf("Nhap toa do diem C: ");
    scanf("%f%f",&x3,&y3);

    float AB,BC,AC;
    AB = do_dai(x1,y1,x2,y2);
    BC = do_dai(x2,y2,x3,y3);
    AC = do_dai(x1,y1,x3,y3);
    
    if(AB<BC+AC && BC<AB+AC && AC<BC+AB){
        if(AB == BC || AB == AC || BC == AC){
            printf("Day la 1 tam giac can\n");
        }else{
            printf("Day khong phai la tam giac can\n");
        }
        float p,chu_vi,dien_tich;
        p = (AB+BC+AC)/2;
        chu_vi = AB+BC+AC;
        dien_tich = sqrt(p*(p-AB)*(p-BC)*(p-AC));
        printf("Chu vi cua tam giac la: %.2f\nDien tich cua tam giac la: %.2f",chu_vi,dien_tich);    
    }else{
        printf("3 diem khong tao thanh tam giac");
    }
    
    return 0;
}
