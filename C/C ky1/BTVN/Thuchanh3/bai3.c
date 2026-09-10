#include <stdio.h>
#include <string.h>
//kieu du lieu ho va ten
typedef struct hovaten{
    char ho[10];
    char dem[20];
    char ten[10];
}hoten;
//khai bao kieu cau truc
typedef struct student{
    hoten name;
    char gender[10];
    float DTB;
}st;
//nhap thong tin sinh vien
void inputStudents(st students[],int n){
    for(int i = 0; i<n; i++){
        printf("\n======== Enter information for student %d ========\n",i+1);
        printf("Enter last name: ");
        scanf("%s",students[i].name.ho);
        getchar();
        printf("Enter middle name: ");
        scanf("%[^\n]",students[i].name.dem);
        getchar();
        printf("Enter first name: ");
        scanf("%s",students[i].name.ten);
        getchar();
        printf("Enter gender: ");
        scanf("%[^\n]",students[i].gender);
        printf("Enter average score: ");
        scanf("%f",&students[i].DTB);
    }
}
//xuat ra thong tin mot sinh vien
void outputStudent(st sv){
    char fullName[30];
    sprintf(fullName, "%s %s %s", sv.name.ho,sv.name.dem,sv.name.ten,sv.gender);
    printf("%-24s | %-10s | %-5.1f\n",fullName,sv.gender,sv.DTB);
}
//sap xep ten tang dan
void arrange(st students[],int n){
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if(strcmp(students[j].name.ten,students[i].name.ten) < 0){
                st tmp;
                tmp = students[i];
                students[i] = students[j];
                students[j] = tmp;
            }
        }
    }
}
//xuat thong tin tat ca sinh vien
void printStudents(st students[], int n){
    arrange(students, n);
    printf("\n================ STUDENTS INFORMATION ================\n");
    printf("%-24s | %-10s | %-5s\n","NAME", "GENDER", "AVERAGE SCORE");
    for(int i = 0; i<n; i++){
        outputStudent(students[i]);
    }
}

int main(){
    //khai bao n la so luong sinh vien
    int n;
    //nhap n
    do{
        printf("Enter n: ");
        scanf("%d",&n);
    }while(n<=0);
    //khai bao mang student voi n phan tu co kieu du lieu la st
    st students[n];
    //nhap thong tin sinh vien
    inputStudents(students, n);
    printStudents(students, n);
    
    return 0;
}

