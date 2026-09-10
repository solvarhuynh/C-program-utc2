#include <stdio.h>
typedef struct sinhVien{
    int MSSV;
    char name[30];
    float Gpa;
} sinhVien; 
void inputSV(sinhVien sv[], int n){
    for(int i = 0; i<n; i++){
        printf("\n============ Nhap sinh vien thu %d ============\n",i+1);
        printf("Enter MSSV: ");
        scanf("%d",&sv[i].MSSV);
        printf("Enter name: ");
        getchar();
        scanf("%[^\n]",sv[i].name);
        printf("Enter GPA: ");
        scanf("%f",&sv[i].Gpa);
    }
}
void outputSv(sinhVien sv){
    printf("| \t%-16d| \t%-24s| \t%-9.1f|\n",sv.MSSV,sv.name,sv.Gpa);
}
void printSvList(sinhVien sv[], int n){
    printf("\n+==================== STUDENT LIST ====================+\n");
    printf("+-----------------+-------------------------+----------+\n");
    printf("|       MSSV      |           NAME          |    GPA   |\n");
    printf("+-----------------+-------------------------+----------+\n");

    for(int i = 0; i<n; i++){
        outputSv(sv[i]);
    }
    printf("+-----------------+-------------------------+----------+\n");
}

sinhVien findSvOfMaxGPA(sinhVien sv[], int n){
    float maxGPA = 0;
    int index = 0;
    for(int i = 0; i<n; i++){
        if(maxGPA < sv[i].Gpa){
            maxGPA = sv[i].Gpa;
            index = i;
        }
    }
    return sv[index];
}

int main(){
    int n;
    do{
        printf("Enter n: ");
        scanf("%d",&n);
    }while(n<=0 || n>50);
    
    sinhVien sv[n];
    inputSV(sv, n);
    printSvList(sv,n);
    printf("\n============= SINH VIEN CO DIEM GPA CAO NHAT ==============\n");
    outputSv(findSvOfMaxGPA(sv,n));
}
 