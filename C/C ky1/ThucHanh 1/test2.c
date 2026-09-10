#include <stdio.h>

typedef struct Student{
    int idStudent;
    char nameStudent[30];
    float GPA;
}Student;

int main(){
    // khai báo danh sách có N sinh viên từ bàn phím
    int n;
    printf("Enter Student number : ");
    scanf("%d",&n);
   
    // khai báo danh sách có N sinh viên
    Student STs[n];
   
    // Nhập danh sách sinh viên
   
    for(int i =0; i <n; i++)
    {
        printf("Enter Info Student %d :\n",i+1);
        printf("ID: ");
        scanf("%d",&STs[i].idStudent);
        printf("NAME: ");
        getchar();
        scanf("%[^\n]",STs[i].nameStudent);
        printf("GPA: ");
        scanf("%f",&STs[i].GPA);
    }

    //in danh sach
    printf("\n=================== STUDENT LIST =================\n");
    printf("+-----------+-------------------------+----------+\n");
    printf("|     ID    |           NAME          |    GPA   |\n");
    printf("+-----------+-------------------------+----------+\n");

    for(int i = 0; i<4; i++){
        printf("| %-10d| %-24s| %-9.1f|\n",STs[i].idStudent,STs[i].nameStudent,STs[i].GPA);
    }
    printf("+-----------+-------------------------+----------+\n");
    
}